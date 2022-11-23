let [...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let [m, n, h] = input.shift().split(" ").map(Number);
let board = [];

// [h][n][m]
for (let i = 0; i < h; i++) {
  board.push(
    input.slice(n * i, n * (i + 1)).map((v) => v.split(" ").map(Number))
  );
}

let vis = Array.from(Array(h), () =>
  Array.from(Array(n), () => Array(m).fill(-1))
);

const nPos = [
  [0, 1, 0],
  [0, 0, 1],
  [0, -1, 0],
  [0, 0, -1],
  [-1, 0, 0],
  [1, 0, 0],
];

let q = [];
let qIdx = 0;

for (let i = 0; i < h; i++) {
  for (let j = 0; j < n; j++) {
    for (let k = 0; k < m; k++) {
      if (board[i][j][k] === 1) {
        q.push({ h: i, x: j, y: k });
        vis[i][j][k] = 0;
      }
      if (board[i][j][k] === -1) vis[i][j][k] = 0;
    }
  }
}

let mx = 0;
while (q.length > qIdx) {
  let cur = q[qIdx++];

  for (let dir = 0; dir < 6; dir++) {
    let nh = cur.h + nPos[dir][0];
    let nx = cur.x + nPos[dir][1];
    let ny = cur.y + nPos[dir][2];

    if (nx < 0 || nx >= n || ny < 0 || ny >= m || nh < 0 || nh >= h) continue;
    if (board[nh][nx][ny] === -1 || vis[nh][nx][ny] > -1) continue;
    q.push({ h: nh, x: nx, y: ny });
    vis[nh][nx][ny] = vis[cur.h][cur.x][cur.y] + 1;
    mx = mx > vis[nh][nx][ny] ? mx : vis[nh][nx][ny];
  }
}

for (let i = 0; i < h; i++) {
  for (let j = 0; j < n; j++) {
    for (let k = 0; k < m; k++) {
      if (vis[i][j][k] === -1) {
        mx = -1;
        console.log(mx);
        return;
      }
    }
  }
}

console.log(mx);
