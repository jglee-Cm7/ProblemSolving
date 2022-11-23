let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let n = Number(input.shift());
let arr = input.map((v) => BigInt(v));
let m = new Map();
let mxCnt = 0;
let mnVal = (1n << 62n) + 1n;

for (let i = 0; i < n; i++) {
  if (m.has(arr[i])) m.set(arr[i], m.get(arr[i]) + 1);
  else m.set(arr[i], 1);
}

for (let [key, value] of m) {
  if (value > mxCnt) {
    mxCnt = value;
    mnVal = key;
  } else if (value === mxCnt && key < mnVal) {
    mnVal = key;
  }
}

console.log(mnVal.toString());
