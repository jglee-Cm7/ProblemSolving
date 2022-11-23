let [n] = require("fs").readFileSync("/dev/stdin").toString().trim().split(/\s/).map(Number);
let ans = [];

function hanoi(a, b, n) {
  if (n === 1) {
    ans.push(`${a} ${b}`);
    return;
  }

  hanoi(a, 6 - a - b, n - 1);
  ans.push(`${a} ${b}`);
  hanoi(6 - a - b, b, n - 1);
}

let cnt = (1 << n) - 1;
hanoi(1, 3, n);
console.log(cnt);
console.log(ans.join("\n"));
