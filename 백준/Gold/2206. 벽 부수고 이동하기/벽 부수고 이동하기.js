let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let [n, m] = input.shift().split(" ").map(Number);
let arr = input.map((v) => [...v].map(Number));
let vis = Array.from(Array(n), () => Array.from(Array(m), () => Array(2).fill(0)));
let answer = -1;
let dx = [0, 1, 0, -1];
let dy = [1, 0, -1, 0];
let q = [{ x: 0, y: 0, c: 0 }];
let qIdx = 0;
vis[0][0][0] = 1;
while (q.length > qIdx) {
  let cur = q[qIdx++];
  if (cur.x === n - 1 && cur.y === m - 1) {
    answer = Math.min(...vis[cur.x][cur.y].filter((v) => v > 0));
    break;
  }
  for (let dir = 0; dir < 4; dir++) {
    let nx = cur.x + dx[dir];
    let ny = cur.y + dy[dir];
    let nc = cur.c;
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (arr[nx][ny] === 1 && cur.c === 1) continue;
    if (arr[nx][ny] === 1 && cur.c === 0) nc++;
    if (vis[nx][ny][nc] > 0) continue;
    q.push({ c: nc, x: nx, y: ny });
    vis[nx][ny][nc] = vis[cur.x][cur.y][cur.c] + 1;
  }
}
console.log(answer);
