let [t, ...arr] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

let q = [];
let dx = [1, 0, -1, 0];
let dy = [0, 1, 0, -1];
let ans = [];

while (t--) {
  let [m, n, k] = arr.shift().split(" ").map(Number);
  let board = Array.from(Array(n), () => Array(m).fill(0));
  let vis = Array.from(Array(n), () => Array(m).fill(0));

  while (k--) {
    let [y, x] = arr.shift().split(" ");
    board[x][y] = 1;
  }

  let cnt = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (vis[i][j] !== 0 || board[i][j] === 0) continue;
      cnt++;
      q.push({ x: i, y: j });
      vis[i][j] = 1;

      while (q.length > 0) {
        let cur = q.pop();

        for (let dir = 0; dir < 4; dir++) {
          let nx = cur.x + dx[dir];
          let ny = cur.y + dy[dir];

          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (vis[nx][ny] > 0 || board[nx][ny] === 0) continue;
          q.push({ x: nx, y: ny });
          vis[nx][ny] = vis[cur.x][cur.y] + 1;
        }
      }
    }
  }
  ans.push(cnt);
}

console.log(ans.join("\n"));