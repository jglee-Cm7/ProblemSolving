let s = require("fs").readFileSync("/dev/stdin").toString().trim();
let ss = new Set();
for (let i = 0; i < s.length; i++) {
  for (let j = 1; i + j <= s.length; j++) ss.add(s.slice(i, i + j));
}
console.log(ss.size);
