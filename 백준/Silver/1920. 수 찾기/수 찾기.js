let [...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

let n = Number(input.shift());
let arr = input.shift().split(" ").map(Number);
let m = Number(input.shift());
let s = input.shift().split(" ").map(Number);
let answer = [];

let w = (k, is, ie) => {
  while (1) {
    let idx = Math.floor((is + ie) / 2);
    if (arr[idx] === k) {
      return idx;
    }

    if (idx === 0 || idx === n - 1 || is === ie) return -1;
    if (k < arr[idx]) ie = idx;
    else is = idx + 1;
  }
};

arr.sort((a, b) => a - b);
for (let i = 0; i < m; i++) {
  let v = w(s[i], 0, n - 1);
  answer.push(v === -1 ? 0 : 1);
}

console.log(answer.join("\n"));
