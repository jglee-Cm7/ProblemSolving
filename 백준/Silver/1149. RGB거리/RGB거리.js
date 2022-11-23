let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let n = Number(input[0]);
let c = input.slice(1).map((v) => v.split(" ").map(Number));
let d = Array.from(Array(n), () => Array(3).fill(0));

d[0] = c[0];
d[1][0] = c[1][0] + Math.min(c[0][1], c[0][2]);
d[1][1] = c[1][1] + Math.min(c[0][0], c[0][2]);
d[1][2] = c[1][2] + Math.min(c[0][0], c[0][1]);

for (let i = 2; i < n; i++) {
  d[i][0] = c[i][0] + Math.min(d[i - 1][1], d[i - 1][2]);
  d[i][1] = c[i][1] + Math.min(d[i - 1][0], d[i - 1][2]);
  d[i][2] = c[i][2] + Math.min(d[i - 1][1], d[i - 1][0]);
}

console.log(Math.min(...d[n - 1]));