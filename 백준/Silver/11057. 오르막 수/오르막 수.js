let n = +require("fs").readFileSync("/dev/stdin").toString().trim();
let d = Array.from(Array(n), () => Array(10).fill(1));
for (let i = 1; i < n; i++) {
  for (let j = 1; j < 10; j++) d[i][j] = (d[i][j - 1] + d[i - 1][j]) % 10007;
}
console.log(d[n - 1].reduce((acc, cur) => acc + cur) % 10007);
