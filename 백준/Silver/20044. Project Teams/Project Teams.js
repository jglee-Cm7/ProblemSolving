let [n, input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
const w = input.split(" ").map((v) => +v);
n = +n;
w.sort((a, b) => a - b);
let mn = Infinity;
for (let i = 0; i < n; i++) mn = Math.min(mn, w[i] + w[w.length - i - 1]);
console.log(mn);
