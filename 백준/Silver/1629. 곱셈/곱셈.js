const pr = (a, b, c) => {
  a = BigInt(a);
  c = BigInt(c);
  if (b === 1) return a % c;
  let v = pr(a, Math.floor(Number(b / 2)), c);
  v = (v * v) % c;
  if (b % 2 === 0) return v;
  else return (v * a) % c;
};

const [a, b, c] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ")
  .map(Number);

console.log(Number(pr(a, b, c)));
