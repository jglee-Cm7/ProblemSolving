let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let n = +input[0];
let arr = input[1].split(" ").map((v) => +v);
let d = [arr[0]];
for (let i = 1; i < n; i++) d.push(Math.max(d[i - 1] + arr[i], arr[i]));
console.log(Math.max(...d));
