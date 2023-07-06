const [n, m] = require("fs").readFileSync("/dev/stdin").toString().trim().split(" ").map((v) => Number(v));
let ans = 0;
if (n === 1) ans = 1;
else if (n === 2) {
  if (m < 8) ans = Math.ceil(m / 2);
  else ans = 4;
} else {
  if (m < 4) ans = m;
  else if (m > 6) ans = m - 2;
  else ans = 4;
}
console.log(ans);
