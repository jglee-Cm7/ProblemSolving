let getLineCount = (arr, len) => {
  let result = 0;
  for (let i = 0; i < arr.length; i++) result += ~~(arr[i] / len);
  return result;
};

let bs = (arr, target) => {
  let st = 1;
  let en = 2 ** 31 - 1;
  while (st <= en) {
    let mid = Math.floor((st + en) / 2);
    let lineCount = getLineCount(arr, mid);
    if (lineCount >= target) st = mid + 1;
    else if (lineCount < target) en = mid - 1;
  }
  return en;
};

let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let [k, n] = input.shift().split(" ").map(Number);
let arr = input.map(Number);

console.log(bs(arr, n));
