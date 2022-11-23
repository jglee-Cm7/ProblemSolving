let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let n = Number(input[0]);
let arr = input[1].split(" ").map(Number);
let d = [arr[0]];

for (let i = 1; i < n; i++) {
  let v = arr[i];
  for (let j = 0; j < i; j++) {
    if (arr[j] < arr[i] && v < d[j] + arr[i]) v = d[j] + arr[i];
  }
  d.push(v);
}

console.log(Math.max(...d));
