const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
const [n, m] = input.shift().split(" ").map((v) => Number(v));
const adj = Array.from({ length: n + 1 }, () => Array.from({ length: n + 1 }).fill(0));
input.map((l) => l.trim().split(" ").map((v) => Number(v))).forEach(([a, b]) => (adj[b][a] = 1));
const dp = Array.from({ length: n + 1 }).fill(1);
let answer = "";
for (let i = 1; i <= n; i++) {
  for (let j = 0; j < i; j++)
    if (adj[i][j]) dp[i] = Math.max(dp[i], dp[j] + 1);
  answer += String(dp[i] + " ");
}
console.log(answer);
