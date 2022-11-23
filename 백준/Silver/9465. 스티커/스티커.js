let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let t = Number(input.shift());
let answer = [];
while (t--) {
  let n = Number(input.shift());
  let p = input.splice(0, 2).map((v) => v.split(" ").map(Number));
  let d = [[0, 0], [p[0][0], p[1][0]]];
  for (let i = 1; i < n; i++) {
    let mx = Math.max(...d[i - 1]);
    d.push([Math.max(mx + p[0][i], d[i][1] + p[0][i]), Math.max(mx + p[1][i], d[i][0] + p[1][i])]);
  }
  answer.push(Math.max(...d[n]));
}
console.log(answer.join("\n"));