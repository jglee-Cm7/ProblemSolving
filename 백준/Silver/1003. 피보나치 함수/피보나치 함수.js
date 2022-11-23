let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let n = Number(input[0]);
let arr = input.slice(1).map((v) => +v);
let answer = [];
let d = Array.from(Array(41), () => Array(2).fill(0));
d[0] = [1, 0];
d[1] = [0, 1];

for (let i = 2; i < 41; i++)
  d[i] = [d[i - 2][0] + d[i - 1][0], d[i - 2][1] + d[i - 1][1]];

for (let i = 0; i < n; i++) answer.push(d[arr[i]].join(" "));

console.log(answer.join("\n"));
