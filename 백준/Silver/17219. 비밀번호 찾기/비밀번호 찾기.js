let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let [n, m] = input[0].split(" ").map(Number);
let arr = input.slice(1, n + 1);
let q = input.slice(n + 1);
let hash = new Map(arr.map((v) => v.split(" ")));
console.log(q.map((v) => hash.get(v)).join("\n"));
