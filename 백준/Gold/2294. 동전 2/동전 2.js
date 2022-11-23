let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let [n, k] = input.shift().split(" ").map(Number);
let arr = input.map(Number);
let d = Array(n + 1).fill(0);
for (let i = 1; i < k + 1; i++) {
  let candi = [];
  for (let j = 0; j < n; j++)
    candi.push(i - arr[j] >= 0 && d[i - arr[j]] !== -1 ? d[i - arr[j]] + 1 : 100001);
  d[i] = Math.min(...candi);
  d[i] = d[i] === 100001 ? -1 : d[i];
}
console.log(d[k]);