let n = +require("fs").readFileSync("/dev/stdin").toString().trim();
let d = [1, 2];
for (let i = 2; i < n; i++) d.push((d[i - 1] + d[i - 2]) % 15746);
console.log(d[n - 1]);
