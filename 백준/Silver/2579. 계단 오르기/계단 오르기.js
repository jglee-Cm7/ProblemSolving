let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let n = Number(input[0]);
let arr = input.slice(1).map(Number);
let d = Array.from(Array(n), () => Array(2).fill(0));
if (n === 1) {
  console.log(arr[0]);
} else {
  d[0][0] = arr[0];
  d[1][0] = arr[1];
  d[1][1] = d[0][0] + arr[1];
  for (let i = 2; i < n; i++) {
    d[i][0] = Math.max(...d[i - 2]) + arr[i];
    d[i][1] = d[i - 1][0] + arr[i];
  }
  console.log(Math.max(...d[n - 1]));
}