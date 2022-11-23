
let [f, s, g, u, d] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ")
  .map(Number);

let vis = Array(f + 1).fill(0);
let q = [];
let qIdx = 0;
let ds = [u, -d];
let answer = "use the stairs";

vis[s] = 1;
q.push(s);

while (q.length > qIdx) {
  let cur = q[qIdx++];

  if (cur === g) {
    answer = vis[cur] - 1;
    break;
  }

  for (let dir = 0; dir < 2; dir++) {
    let ns = cur + ds[dir];

    if (ns < 1 || ns >= vis.length) continue;
    if (vis[ns] > 0) continue;
    vis[ns] = vis[cur] + 1;
    q.push(ns);
  }
}

console.log(answer);
