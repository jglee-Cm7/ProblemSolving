let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let n = Number(input[0]);
let arr = input[1].split(" ").map(Number);
let d = [1];

for (let i = 1; i < n; i++) {
  let v = 1;
  for (let j = 0; j < i; j++) {
    if (arr[j] < arr[i] && v <= d[j]) v = d[j] + 1;
  }
  d.push(v);
}

console.log(Math.max(...d));
