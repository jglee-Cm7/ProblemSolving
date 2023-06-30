const [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");

const n = input.shift().trim();
const arr = input.map((v) => Number(v.trim()));
const dp = Array.from({ length: n }).fill(0);
dp[0] = arr[0];
for (let i = 1; i < n; i++) dp[i] = Math.max(dp[i - 1] * arr[i], arr[i]);

console.log(Math.max(...dp).toFixed(3));
