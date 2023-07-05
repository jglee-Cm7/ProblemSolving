let [n, arr] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
n = Number(n);
arr = arr.split(" ").map((v) => Number(v));
let dp = Array.from({ length: n }).fill(Infinity);
dp[0] = 0;
for (let i = 0; i < n; i++) {
  for (let j = 1; j <= arr[i]; j++) {
    if (i + j >= n) continue;
    dp[i + j] = Math.min(dp[i + j], dp[i] + 1);
  }
}
console.log(dp[n - 1] === Infinity ? -1 : dp[n - 1]);
