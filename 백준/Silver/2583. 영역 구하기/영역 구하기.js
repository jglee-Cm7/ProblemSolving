let [...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

let [n, m, k] = input.shift().split(" ").map(Number);
let board = Array.from(Array(n), () => Array(m).fill(0));
let vis = Array.from(Array(n), () => Array(m).fill(0));
let dx = [1, 0, -1, 0];
let dy = [0, 1, 0, -1];
let q = [];

while (k--) {
  let [sy, sx, ey, ex] = input.shift().split(" ").map(Number);

  for (let i = sx; i < ex; i++) {
    for (let j = sy; j < ey; j++) {
      board[i][j]++;
    }
  }
}

let cnt = 0;
let areas = [];
for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (board[i][j] === 0 && vis[i][j] === 0) {
      q.push({ x: i, y: j });
      vis[i][j] = 1;
      cnt++;
      let area = 0;
      while (q.length > 0) {
        let cur = q.pop();
        area++;

        for (let dir = 0; dir < 4; dir++) {
          let nx = cur.x + dx[dir];
          let ny = cur.y + dy[dir];

          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (board[nx][ny] > 0 || vis[nx][ny] > 0) continue;
          vis[nx][ny] = vis[cur.x][cur.y] + 1;
          q.push({ x: nx, y: ny });
        }
      }
      areas.push(area);
    }
  }
}

console.log(cnt);
console.log(areas.sort((a, b) => a - b).join(" "));