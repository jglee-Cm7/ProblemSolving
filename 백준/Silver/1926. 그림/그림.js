const [...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const [n, m] = input.splice(0, 1)[0].split(" ");
let board = input.map((v) => v.split(" ").map(Number));
let vis = Array.from({ length: 505 }, (v, i) =>
  Array.from({ length: 505 }, (v, i) => 0)
);
const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];
let mx = 0;
let num = 0;

for (let i = 0; i < n; ++i) {
  for (let j = 0; j < m; ++j) {
    if (board[i][j] === 0 || vis[i][j] === 1) continue;
    num++;

    const s = [];
    vis[i][j] = 1;
    s.push({ x: i, y: j });
    let area = 0;
    // DFS
    while (s.length !== 0) {
      area++;
      let cur = s.pop();
      for (let dir = 0; dir < 4; ++dir) {
        let nx = cur.x + dx[dir];
        let ny = cur.y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (vis[nx][ny] || board[nx][ny] !== 1) continue;
        vis[nx][ny] = 1;
        s.push({ x: nx, y: ny });
      }
    }
    mx = mx > area ? mx : area;
  }
}

console.log(`${num}\n${mx}`);
