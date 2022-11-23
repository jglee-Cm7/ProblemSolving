let [...arr] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n").map(Number);
let n = arr.shift();
arr.sort((a, b) => a - b);
let answer = [];

for (let i = 0; i < n; i++) {
  answer.push(arr[i] * (n - i));
}

console.log(Math.max(...answer));
