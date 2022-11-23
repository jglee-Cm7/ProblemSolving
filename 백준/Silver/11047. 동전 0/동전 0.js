let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let [n, k] = input.shift().split(" ").map(Number);
let arr = input.map(Number);
let cnt = 0;
for (let i = n - 1; i >= 0; i--) {
  if (arr[i] <= k) {
    cnt += ~~(k / arr[i]);
    k %= arr[i];
  }
}
console.log(cnt);
