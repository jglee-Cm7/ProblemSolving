let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let [n, m] = input.shift().split(" ").map((v) => +v);
let arr = input.map((v) => [...v].map(Number));
let d = Array.from(Array(n + 1), () => Array(m + 1).fill(0));
let mx = 0;
for (let i = 1; i < n + 1; i++) {
  for (let j = 1; j < m + 1; j++) {
    if (arr[i - 1][j - 1]) {
      d[i][j] = Math.min(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]) + 1;
      mx = mx > d[i][j] ? mx : d[i][j];
    }
  }
}
console.log(mx * mx);
