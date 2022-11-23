let n = Number(require("fs").readFileSync("/dev/stdin").toString().trim());
let d = [[0, 1, 1, 1, 1, 1, 1, 1, 1, 1]];
for (let i = 1; i < n; i++) {
  nd = Array(10).fill(0);
  for (let j = 0; j < 10; j++) {
    nd[j] += (j - 1 >= 0 ? d[i - 1][j - 1] : 0) + (j + 1 < 10 ? d[i - 1][j + 1] : 0);
    nd[j] %= 1000000000;
  }
  d.push(nd);
}
console.log(d[n - 1].reduce((acc, cur) => acc + cur) % 1000000000);
