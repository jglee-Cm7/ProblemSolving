let [n, ...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
n = Number(n);

let board = input.map((x) => [...x].map(Number));
let vis = Array.from(Array(n), () => Array(n).fill(0));
let dx = [1, 0, -1, 0];
let dy = [0, 1, 0, -1];
let q = [];
let qIdx = 0;
let cnt = 0;
let areas = [];

for (let i = 0; i < n; i++) {
  for (let j = 0; j < n; j++) {
    if (board[i][j] === 1 && vis[i][j] === 0) {
      cnt++;
      q.push({ x: i, y: j });
      vis[i][j] = 1;

      let area = 0;
      while (q.length > qIdx) {
        cur = q[qIdx++];
        area++;

        for (let dir = 0; dir < 4; dir++) {
          let nx = cur.x + dx[dir];
          let ny = cur.y + dy[dir];

          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if (board[nx][ny] === 0 || vis[nx][ny] > 0) continue;
          vis[nx][ny] = vis[cur.x][cur.y] + 1;
          q.push({ x: nx, y: ny });
        }
      }
      areas.push(area);
    }
  }
}

console.log(cnt);
console.log(areas.sort((a, b) => a - b).join("\n"));
