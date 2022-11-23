let [...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let s = [...input.shift()];
let alpha = [..."abcdefghijklmnopqrstuvwxyz"];
let answer = [];

for (let i = 0; i < alpha.length; i++) {
  answer.push(s.filter((x) => x === alpha[i]).length);
}

console.log(answer.join(" "));
