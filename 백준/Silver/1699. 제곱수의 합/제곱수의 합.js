let n = +require("fs").readFileSync("/dev/stdin").toString().trim();
let d = Array(n + 1).fill(0);
for (let i = 1; i < n + 1; i++) {
  let mn = d[i - 1] + 1;
  for (let j = 2; j < ~~Math.sqrt(i) + 1; j++)
    mn = d[i - j ** 2] + 1 < mn ? d[i - j ** 2] + 1 : mn;
  d[i] = mn;
}
console.log(d[n]);
