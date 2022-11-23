let n = +require("fs").readFileSync("/dev/stdin").toString().trim();
let d = [0, 1];
let absN = Math.abs(n);
for (let i = 2; i <= absN; i++) d.push((d[i - 1] + d[i - 2]) % 1000000000);
console.log(absN === 0 ? 0 : absN % 2 === 0 && n < 0 ? -1 : 1);
console.log(d[absN]);
