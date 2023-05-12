let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let [n, k] = input.shift().split(" ").map(Number);
let items = input.map((item) => item.split(" ").map(Number));
let dp = Array.from({ length: n + 1 }, () => Array(k + 1).fill(0));

for (let i = 1; i <= n; i++) {
  for (let j = 1; j <= k; j++) {
    dp[i][j] = dp[i - 1][j];
    let [w, v] = items[i - 1];
    if (j - w >= 0) dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - w] + v);
  }
}

console.log(dp[n][k]);
