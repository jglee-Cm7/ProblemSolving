let [n, m] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ")
  .map(Number);

let used = Array(n + 1).fill(0);
let arr = Array(m).fill(0);
let answer = [];

let r = (n, m, k) => {
  if (k === m) {
    answer.push(arr.join(" "));
    return;
  }

  for (let i = 1; i < n + 1; i++) {
    if (!used[i]) {
      arr[k] = i;
      used[i] = 1;
      r(n, m, k + 1);
      used[i] = 0;
    }
  }
};

r(n, m, 0);
console.log(answer.join("\n"));
