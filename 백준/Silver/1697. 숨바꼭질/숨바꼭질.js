let [n, k] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ")
  .map(Number);

let vis = Array.from(Array(100005), () => -1);
let q = [];
let dx = [-1, 1, "*2"];
q.push(n);
vis[n] = 0;

while (q.length > 0) {
  cur = q.shift();

  for (let dir = 0; dir < 3; dir++) {
    let nx = cur;
    if (dx[dir] === "*2") nx *= 2;
    else nx += dx[dir];

    if (nx < 0 || nx >= 100005) continue;
    if (vis[nx] > -1) continue;

    vis[nx] = vis[cur] + 1;

    if (vis[k] !== -1) {
      console.log(vis[k]);
      return;
    }
    q.push(nx);
  }
}
