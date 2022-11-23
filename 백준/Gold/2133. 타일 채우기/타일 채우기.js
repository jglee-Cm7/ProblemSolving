let n = +require("fs").readFileSync("/dev/stdin").toString().trim();
let d = [1, 0, 3];
for (let i = 3; i < n + 1; i++) {
  let v = d[i - 2] * d[2];
  for (let j = i - 4; j >= 0; j -= 2) v += d[j] * 2;
  d.push(v);
}
console.log(d[n]);
