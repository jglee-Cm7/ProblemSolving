let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let n = Number(input[0]);
let arr = input[1].split(" ").map(Number);
let d = [1];
let d2 = [-1];
let mxIdx = 0;
let answer = [];
for (let i = 1; i < n; i++) {
  let v = 1;
  let idx = -1;
  for (let j = 0; j < i; j++) {
    if (arr[j] < arr[i] && v <= d[j]) {
      v = d[j] + 1;
      idx = j;
    }
  }
  d.push(v);
  d2.push(idx);
  mxIdx = v > d[mxIdx] ? i : mxIdx;
}
while (mxIdx >= 0) {
  answer.push(arr[mxIdx]);
  mxIdx = d2[mxIdx];
}
console.log(Math.max(...d));
console.log(answer.reverse().join(" "));