let n = Number(require("fs").readFileSync("/dev/stdin").toString().trim());
let vis = Array(n + 1).fill(0);
let q = [];
let qIdx = 0;

q.push(n);
vis[n] = 1;

while (q.length > qIdx) {
  let cur = q[qIdx++];
  if (cur === 1) {
    console.log(vis[cur] - 1);
    return;
  }

  if (cur % 3 === 0 && vis[cur / 3] === 0) {
    q.push(cur / 3);
    vis[cur / 3] = vis[cur] + 1;
  }
  if (cur % 2 === 0 && vis[cur / 2] === 0) {
    q.push(cur / 2);
    vis[cur / 2] = vis[cur] + 1;
  }
  if (cur - 1 > 0 && vis[cur - 1] === 0) {
    q.push(cur - 1);
    vis[cur - 1] = vis[cur] + 1;
  }
}
