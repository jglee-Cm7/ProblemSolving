let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let t = input.shift();
let d = Array(10001).fill(0);
let answer = [];
while (t--) {
  d.fill(0);
  d[0] = 1;
  let n = +input.shift();
  let arr = input.shift().split(" ").map((v) => +v);
  let m = +input.shift();
  for (let i = 0; i < n; i++) {
    for (let j = arr[i]; j < m + 1; j++) d[j] += d[j - arr[i]];
  }
  answer.push(d[m]);
}
console.log(answer.join("\n"));
