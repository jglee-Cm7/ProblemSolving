let n = +require("fs").readFileSync("/dev/stdin").toString().trim();
let d = [1n, 1n, 2n];
for (let i = 3; i < n; i++) {
  d.push(1n + d.slice(0, i - 1).reduce((acc, cur) => acc + cur));
}

console.log(d[n - 1].toString());
