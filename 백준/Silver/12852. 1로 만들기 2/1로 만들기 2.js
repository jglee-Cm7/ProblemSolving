let n = Number(require("fs").readFileSync("/dev/stdin").toString().trim());
let d = Array.from(Array(n + 1), () => Array(2).fill(0));

d[1][1] = 1;
if (n > 1) d[2][1] = 1;
for (let i = 2; i < n + 1; i++) {
  let mn = d[i - 1][0];
  let pIdx = i - 1;
  if (i % 3 === 0 && d[i / 3][0] < mn) {
    mn = d[i / 3][0];
    pIdx = i / 3;
  }
  if (i % 2 === 0 && d[i / 2][0] < mn) {
    mn = d[i / 2][0];
    pIdx = i / 2;
  }

  d[i][0] = mn + 1;
  d[i][1] = pIdx;
}

let s = n;
let answer = [n];

while (s !== 1) {
  s = d[s][1];
  answer.push(s);
}
console.log(d[n][0]);
console.log(answer.join(" "));
