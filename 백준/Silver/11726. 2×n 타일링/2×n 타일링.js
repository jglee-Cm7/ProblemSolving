let n = Number(require("fs").readFileSync("/dev/stdin").toString().trim());
let d = [0, 1, 2];
for (let i = 3; i < n + 1; i++) d.push((d[i - 2] + d[i - 1]) % 10007);
console.log(d[n]);
