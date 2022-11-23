let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let n = Number(input[0]);
let arr = input.slice(1).map((v) => v.split(" ").map(Number));
let d = Array(20).fill(0);
for (let i = n - 1; i >= 0; i--) {
  if (i + arr[i][0] <= n) d[i] = Math.max(d[i + arr[i][0]] + arr[i][1], d[i + 1]);
  else d[i] = d[i + 1];
}
console.log(Math.max(...d));
