let [...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let [n, s] = input.shift().split(" ").map(Number);
let arr = input.shift().split(" ").map(Number);
let answer = [];

let r = (k, sum) => {
  if (n === k) {
    if (sum === s) answer.push(sum);
    return;
  }
  r(k + 1, sum);
  r(k + 1, sum + arr[k]);
};

r(0, 0);

console.log(s === 0 ? answer.length - 1 : answer.length);
