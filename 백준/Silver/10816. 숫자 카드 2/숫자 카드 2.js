let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");

let n = Number(input.shift());
let arr = input.shift().split(" ").map(Number);
let m = Number(input.shift());
let s = input.shift().split(" ").map(Number);
let mm = new Map();
let answer = [];

for (let i = 0; i < n; i++) {
  if (mm.has(arr[i])) mm.set(arr[i], mm.get(arr[i]) + 1);
  else mm.set(arr[i], 1);
}

for (let i = 0; i < m; i++) {
  answer.push(mm.get(s[i]) ?? 0);
}

console.log(answer.join(" "));
