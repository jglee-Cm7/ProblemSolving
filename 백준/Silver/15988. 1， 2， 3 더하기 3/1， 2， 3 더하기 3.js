let arr = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n").slice(1).map((v) => +v);
let d = [0, 1, 2, 4];
let answer = [];
for (let i = 4; i < Math.max(...arr) + 1; i++) d.push((d[i - 1] + d[i - 2] + d[i - 3]) % 1000000009);
for (let i = 0; i < arr.length; i++) answer.push(d[arr[i]]);
console.log(answer.join("\n"));