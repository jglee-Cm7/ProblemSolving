let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let n = +input.shift();
let arr = input.shift().split(" ").map(Number);
let m = +input.shift();
let q = input.map((v) => v.split(" ").map(Number));
let d = Array.from(Array(n + 1), () => Array(n).fill(1));
let answer = [];
for (let i = 0; i < n; i++) {
  for (let j = 0; j <= i; j++) {
    if (i === j) d[j][i] = 1;
    else d[j][i] = arr[i] === arr[j] ? d[j + 1][i - 1] : 0;
  }
}
q.map(([s, e]) => answer.push(d[s - 1][e - 1]));
console.log(answer.join("\n"));
