const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
const [n, m] = input.shift().split(" ").map((v) => v.trim());
const arr = input.map((v) => +v);
const mn = Math.min(n, m);
arr.sort((a, b) => b - a);

let mx = 0;
let p = 0;
for (let i = 0; i < m; i++) {
  let tot = 0;
  for (let j = 0; j < mn; j++) if (arr[j] >= arr[i]) tot += arr[i];
  if (tot > mx) {
    mx = tot;
    p = arr[i];
  }
}
console.log(p, mx);
