let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let [n, m] = input[0].split(" ").map(Number);
let arr = input[1].split(" ").map(Number);
let q = input.slice(2).map((v) => v.split(" ").map(Number));
let d = [0];
let answer = [];
for (let i = 0; i < n; i++) d.push(d[i] + arr[i]);
for (let i = 0; i < q.length; i++) answer.push(d[q[i][1]] - d[q[i][0] - 1]);
console.log(answer.join("\n"));
