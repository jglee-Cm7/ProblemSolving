let [...arr] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let [n, m, v] = arr.shift().split(" ").map(Number);
arr = arr.map((v) => v.split(" ").map(Number));
let adj = Array.from(Array(n + 1), () => new Array());
let vis = Array(n + 1).fill(0);
let q = [];
let qIdx = 0;

for (let i = 0; i < m; i++) {
  adj[arr[i][0]].push(arr[i][1]);
  adj[arr[i][1]].push(arr[i][0]);
}
for (let i = 1; i < n + 1; i++) adj[i].sort((a, b) => a - b);
let answer = [];

/** DFS */
let d = [];
let dfs = (v) => {
  d.push(v);
  for (let i = 0; i < adj[v].length; i++) {
    if (vis[adj[v][i]] !== 0) continue;
    vis[adj[v][i]] = vis[v] + 1;
    dfs(adj[v][i]);
  }
};
vis[v] = 1;
dfs(v);

/** BFS */
vis.fill(0);
let b = [v];
vis[v] = 1;
for (let i = 0; i < adj[v].length; i++) {
  q.push(adj[v][i]);
  vis[adj[v][i]] = 2;
}

while (q.length > qIdx) {
  let cur = q[qIdx++];
  b.push(cur);
  for (let i = 0; i < adj[cur].length; i++) {
    if (vis[adj[cur][i]] !== 0) continue;
    q.push(adj[cur][i]);
    vis[adj[cur][i]] = vis[cur] + 1;
  }
}

answer.push(d.join(" "));
answer.push(b.join(" "));
console.log(answer.join("\n"));
