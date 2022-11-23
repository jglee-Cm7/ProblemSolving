let [...arr] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let n = Number(arr[0]);
let a = arr[1].split(" ").map(Number);
let b = arr[2].split(" ").map(Number);
let s = 0;
a.sort((a, b) => a - b);
b.sort((a, b) => b - a);

for (let i = 0; i < n; i++) s += a[i] * b[i];

console.log(s);
