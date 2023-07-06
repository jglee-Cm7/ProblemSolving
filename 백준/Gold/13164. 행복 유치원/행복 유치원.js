let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let [n, k] = input.shift().split(" ").map((v) => Number(v));
let arr = input.shift().split(" ").map((v) => Number(v));
let dif = [];
for (let i = 1; i < n; i++) dif.push(arr[i] - arr[i - 1]);
dif.sort((a, b) => a - b);
for (let i = 0; i < k - 1; i++) dif.pop();
console.log(dif.reduce((a, b) => a + b, 0));
