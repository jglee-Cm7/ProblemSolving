let arr = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n").slice(1).map((v) => +v);
let d = [1, 1, 1, 2, 2];
let answer = [];
for (let i = 5; i < 100; i++) d.push(d[i - 2] + d[i - 3]);
for (let i = 0; i < arr.length; i++) answer.push(d[arr[i] - 1]);
console.log(answer.join("\n"));