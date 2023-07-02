const n = +require("fs").readFileSync("/dev/stdin").toString().trim();
const dp = [1, 1];
for (let i = 2; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2] + 1) % 1000000007;
console.log(dp[n]);
