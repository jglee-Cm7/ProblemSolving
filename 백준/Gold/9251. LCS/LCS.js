let [s1, s2] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let d = Array.from(Array(s1.length + 1), () => Array(s2.length + 1).fill(0));
for (let i = 1; i < s1.length + 1; i++) {
  for (let j = 1; j < s2.length + 1; j++) {
    if (s1[i - 1] === s2[j - 1]) d[i][j] = d[i - 1][j - 1] + 1;
    else d[i][j] = Math.max(d[i - 1][j], d[i][j - 1]);
  }
}
console.log(Math.max(...d[s1.length]));