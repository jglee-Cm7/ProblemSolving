const [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");

const n = input.shift().trim();
const arr = input.map((v) => Number(v.trim()));

let answer = 0;
for (let i = 0; i < n; i++) {
  let mx = arr[i];
  answer = Math.max(answer, mx);
  for (let j = i + 1; j < n; j++) {
    mx = mx * arr[j];
    answer = Math.max(answer, mx);
  }
}

console.log(answer.toFixed(3));
