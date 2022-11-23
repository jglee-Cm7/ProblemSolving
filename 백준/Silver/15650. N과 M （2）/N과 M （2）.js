let [n, m] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ")
  .map(Number);

let used = Array(n).fill(0);
let arr = Array(m).fill(0);
let answer = [];

let r = (k) => {
  if (k === m) {
    answer.push(arr.join(" "));
    return;
  }

  for (let i = 0; i < n; i++) {
    if (!used[i]) {
      if (k - 1 >= 0 && arr[k - 1] > i + 1) continue;
      used[i] = 1;
      arr[k] = i + 1;

      r(k + 1);
      used[i] = 0;
    }
  }
};

r(0);

console.log(answer.join("\n"));
