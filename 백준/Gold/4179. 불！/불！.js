const [...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
const [n, m] = input.splice(0, 1)[0].split(" ").map(Number);
let board = input.map((v) => [...v]);
let distJ = Array.from(Array(n), () => Array(m).fill(-1));
let distF = Array.from(Array(n), () => Array(m).fill(-1));

const q1 = [];
const q2 = [];
const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];
let result = "IMPOSSIBLE";

for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (board[i][j] === "F") {
      distF[i][j] = 0;
      q1.push({ x: i, y: j, t: 0 });
    }
    if (board[i][j] === "J") {
      distJ[i][j] = 0;
      q2.push({ x: i, y: j, t: 0 });
    }
  }
}

// BFS For F
while (q1.length > 0) {
  let cur = q1.shift();

  for (let dir = 0; dir < 4; dir++) {
    let nx = cur.x + dx[dir];
    let ny = cur.y + dy[dir];
    let nt = cur.t + 1;
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (board[nx][ny] === "#" || board[nx][ny] === "F" || distF[nx][ny] >= 0)
      continue;
    distF[nx][ny] = nt;
    q1.push({ x: nx, y: ny, t: nt });
  }
}

// console.log(distF);

// BFS For J
while (q2.length > 0) {
  let cur = q2.shift();

  for (let dir = 0; dir < 4; dir++) {
    let nx = cur.x + dx[dir];
    let ny = cur.y + dy[dir];
    let nt = cur.t + 1;
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
      console.log(nt);
      return;
    }
    if (board[nx][ny] !== "." || distJ[nx][ny] >= 0) continue;
    if (distF[nx][ny] !== -1 && distF[nx][ny] <= nt) continue;
    distJ[nx][ny] = nt;
    q2.push({ x: nx, y: ny, t: nt });
  }
  // console.log(distJ);
}

console.log(result);
