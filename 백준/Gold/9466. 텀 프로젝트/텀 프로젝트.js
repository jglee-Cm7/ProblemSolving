let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let t = +input.shift();
let answer = [];
let vis = Array(100001).fill(0);
while (t--) {
  vis.fill(0);
  let n = +input.shift();
  let arr = [0, ...input.shift().split(" ").map(Number)];
  for (let i = 1; i <= n; i++) {
    if (vis[i] === 0) {
      let cur = i;
      while (1) {
        vis[cur] = i;
        cur = arr[cur];
        if (vis[cur] === i) {
          while (vis[cur] !== -1) {
            vis[cur] = -1;
            cur = arr[cur];
          }
          break;
        } else if (vis[cur] !== 0) break;
      }
    }
  }
  answer.push(vis.slice(1, n + 1).filter((v) => v !== -1).length);
}
console.log(answer.join("\n"));