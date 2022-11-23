let [...arr] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let [n, m] = arr.shift().split(" ").map(Number);
arr = arr.map((v) => v.split(" ").map(Number));
let adj = Array.from(Array(n + 1), () => new Array());
let vis = Array(n + 1).fill(0);
let q = [];
let qIdx = 0;

for (let i = 0; i < m; i++) {
  adj[arr[i][0]].push(arr[i][1]);
  adj[arr[i][1]].push(arr[i][0]);
}

let cnt = 0;
for (let i = 1; i < n + 1; i++) {
  if (vis[i] === 0) {
    vis[i] = 1;
    cnt++;

    for (let j = 0; j < adj[i].length; j++) {
      if (vis[adj[i][j]] === 0) {
        q.push(adj[i][j]);
        vis[adj[i][j]] = vis[i] + 1;
      }
    }

    while (q.length > qIdx) {
      let cur = q[qIdx++];
      for (let k = 0; k < adj[cur].length; k++) {
        if (vis[adj[cur][k]] === 0) {
          q.push(adj[cur][k]);
          vis[adj[cur][k]] = vis[cur] + 1;
        }
      }
    }
  }
}
console.log(cnt);
