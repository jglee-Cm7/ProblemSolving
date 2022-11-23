const [n, ...arr] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map(Number);

const s = [];
let count = 1;
let answer = [];

for (let i = 1; i < arr[0] + 1; ++i) {
  answer.push("+");
  s.push(count++);
}

for (const v of arr) {
  if (s[s.length - 1] > v) {
    console.log("NO");
    return;
  } else if (s[s.length - 1] === v) {
    answer.push("-");
    s.pop();
  } else {
    for (let i = count; i < v + 1; ++i) {
      answer.push("+");
      s.push(count++);
    }
    answer.push("-");
    s.pop();
  }
}

console.log(answer.join("\n"));
