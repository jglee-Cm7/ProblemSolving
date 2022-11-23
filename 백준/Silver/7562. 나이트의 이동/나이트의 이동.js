let [t, ...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
t = Number(t);
let answer = [];

const dx = [-2, -1, 1, 2, 2, 1, -1, -2];
const dy = [1, 2, 2, 1, -1, -2, -2, -1];

while (t--) {
  let l = Number(input.shift());
  let vis = Array.from(Array(l), () => Array(l).fill(0));
  let from = input.shift().split(" ").map(Number);
  let to = input.shift().split(" ").map(Number);
  let q = [];

  q.push({ x: from[0], y: from[1] });

  while (q.length > 0) {
    let cur = q.shift();

    if (cur.x === to[0] && cur.y === to[1]) {
      answer.push(vis[cur.x][cur.y]);
      break;
    }

    for (let dir = 0; dir < 8; dir++) {
      let nx = cur.x + dx[dir];
      let ny = cur.y + dy[dir];

      if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
      if (vis[nx][ny] > 0) continue;

      q.push({ x: nx, y: ny });
      vis[nx][ny] = vis[cur.x][cur.y] + 1;
    }
  }
}

console.log(answer.join("\n"));