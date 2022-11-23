let [n, m, ...arr] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n").map((v) => +v);
let d = [1, 2];
for (let i = 2; i < 40; i++) d.push(d[i - 1] + d[i - 2]);
let idx = [];
let s = 1;
for (let i = 0; i < m; i++) {
  if (arr[i] - s > 0) idx.push(arr[i] - s);
  s = arr[i] + 1;
}
if (n + 1 - s > 0) idx.push(n + 1 - s);
console.log(idx.length > 0 ? idx.map((v) => d[v - 1]).reduce((acc, cur) => acc * cur) : 1);
