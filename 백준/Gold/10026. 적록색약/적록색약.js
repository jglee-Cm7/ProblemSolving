const [...arr] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
const n = Number(arr.shift());
const board = arr.map((v) => [...v]);
let dx = [-1, 0, 1, 0];
let dy = [0, 1, 0, -1];

// B - Flood Fill
let r = FP(n, ["R"]);
let g = FP(n, ["G"]);
let b = FP(n, ["B"]);
let rg = FP(n, ["R", "G"]);
let answer = [r + g + b, rg + b];

console.log(answer.join(" "));

function FP(n, color) {
  let vis = Array.from(Array(n), () => Array(n).fill(0));
  let q = [];
  let cnt = 0;

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (vis[i][j] > 0 || !color.includes(board[i][j])) continue;
      q.push({ x: i, y: j });
      vis[i][j] = 1;
      cnt++;

      while (q.length > 0) {
        let cur = q.pop();
        for (let dir = 0; dir < 4; dir++) {
          let nx = cur.x + dx[dir];
          let ny = cur.y + dy[dir];

          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if (vis[nx][ny] > 0 || !color.includes(board[nx][ny])) continue;
          q.push({ x: nx, y: ny });
          vis[nx][ny] = vis[cur.x][cur.y] + 1;
        }
      }
    }
  }
  return cnt;
}
