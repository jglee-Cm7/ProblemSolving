let [n, ...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
const stat = input.map((l) => l.trim().split(" ").map((v) => Number(v)));
n = Number(n);
let tot = 0;
let sum = Array.from({ length: n }).fill(0);
for (let i = 0; i < n; i++) {
  for (let j = 0; j < n; j++) {
    tot += stat[i][j];
    sum[i] += stat[i][j];
    sum[j] += stat[i][j];
  }
}

let cs = [];
let isUsed = Array.from({ length: n }).fill(0);
const backtraking = (k, j, m) => {
  if (k === m) {
    cs.push([...isUsed]);
    return;
  }

  for (let i = j; i < n; i++) {
    if (isUsed[i]) continue;
    isUsed[i] = 1;
    backtraking(k + 1, i + 1, m);
    isUsed[i] = 0;
  }
};
for (let i = 1; i < n; i++) backtraking(0, 0, i);

let answer = Infinity;
cs.forEach((arr) => {
  let m = 0;
  for (let i = 0; i < n; i++) if (arr[i]) m += sum[i];
  answer = Math.min(answer, Math.abs(tot - m));
});
console.log(answer);