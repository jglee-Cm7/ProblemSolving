let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let [n, m] = input[0].split(" ").map(Number);
let arr = input.slice(1, n + 1);
let q = input.slice(n + 1);
let hash = new Map(arr.map((v, i) => [v, i + 1]));
console.log(q.map((v) => (Number.isNaN(+v) ? hash.get(v) : arr[+v - 1])).join("\n"));
