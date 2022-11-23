let n = Number(require("fs").readFileSync("/dev/stdin").toString().trim());
let d = [0n, 1n];
for (let i = 2; i < n + 1; i++) d.push(d[i - 1] + d[i - 2]);
console.log(d[n].toString());
