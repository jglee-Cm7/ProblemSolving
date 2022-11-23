let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let n = Number(input.shift());
let arr = input.map((v) => v.split(" ").map(Number));

arr.sort((a, b) => (a[1] === b[1] ? a[0] - b[0] : a[1] - b[1]));
let s = 0;
let cnt = 0;

for (let i = 0; i < n; i++) {
  if (s <= arr[i][0]) {
    s = arr[i][1];
    cnt++;
  }
}

console.log(cnt);
