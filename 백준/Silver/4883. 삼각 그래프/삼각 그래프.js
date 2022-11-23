let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let idx = 0, t = 1, answer = [];
while (input[idx] !== "0") {
  let n = +input[idx++];
  let arr = input.slice(idx, idx + n).map((v) => v.split(" ").map(Number));
  idx += n;
  let d = [[1001, arr[0][1], arr[0][2] < 0 ? arr[0][1] + arr[0][2] : 1001]];
  for (let i = 1; i < n; i++) {
    let first = Math.min(d[i - 1][0] + arr[i][0], d[i - 1][1] + arr[i][0]);
    let second = Math.min(first + arr[i][1], d[i - 1][0] + arr[i][1], d[i - 1][1] + arr[i][1], d[i - 1][2] + arr[i][1]);
    let third = Math.min(second + arr[i][2], d[i - 1][1] + arr[i][2], d[i - 1][2] + arr[i][2]);
    d.push([first, second, third]);
  }
  answer.push(`${t++}. ${d[n - 1][1]}`);
}
console.log(answer.join("\n"));
