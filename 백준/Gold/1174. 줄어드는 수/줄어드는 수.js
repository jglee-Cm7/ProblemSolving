let n = +require("fs").readFileSync("/dev/stdin").toString().trim();
let m = 10;

const answer = [];
const arr = [];
const bt = () => {
  if (arr.length) answer.push(+arr.join(""));
 
  for (let i = 0; i < m; i++) {
    if (arr.length === 0 || arr.at(-1) > i) {
      arr.push(i);
      bt();
      arr.pop();
    }
  }
};
bt();
answer.sort((a, b) => a - b);
console.log(answer[n - 1] ?? -1);
