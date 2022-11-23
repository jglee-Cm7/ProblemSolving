let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let n = Number(input[0]);
let arr = input.slice(1).map((v) => v.split(" ").map(Number));
let d = Array.from(Array(n), () => Array(1).fill(0));
d[0].push(arr[0][0]);

for (let i = 1; i < n; i++) {
  for (let j = 0; j < arr[i].length; j++) {
    d[i].push( Math.max(d[i - 1][j] + arr[i][j], (d[i - 1][j + 1] ?? 0) + arr[i][j]));
  }
}

console.log(Math.max(...d[n - 1]));
