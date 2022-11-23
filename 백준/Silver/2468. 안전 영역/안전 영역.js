
let [...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let n = Number(input.shift());
let board = input.map((v) => v.split(" ").map(Number));
let q = [];
let qIdx = 0;
let dx = [-1, 0, 1, 0];
let dy = [0, 1, 0, -1];

let mxh = 0;
for (let i = 0; i < n; i++) {
  for (let j = 0; j < n; j++) {
    mxh = mxh > board[i][j] ? mxh : board[i][j];
  }
}

let mxArea = 0;
for (let k = 0; k <= mxh; k++) {
  let vis = Array.from(Array(n), () => Array(n).fill(0));
  let cnt = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (board[i][j] >= k && vis[i][j] === 0) {
        q.push({ x: i, y: j });
        vis[i][j] = 1;
        cnt++;

        while (q.length > qIdx) {
          let cur = q[qIdx++];

          for (let dir = 0; dir < 4; dir++) {
            let nx = cur.x + dx[dir];
            let ny = cur.y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] < k || vis[nx][ny] > 0) continue;
            q.push({ x: nx, y: ny });
            vis[nx][ny] = vis[cur.x][cur.y] + 1;
          }
        }
      }
    }
  }
  mxArea = mxArea > cnt ? mxArea : cnt;
}

console.log(mxArea);
