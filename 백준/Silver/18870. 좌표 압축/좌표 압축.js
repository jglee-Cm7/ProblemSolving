let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");

let n = Number(input.shift());
let arr = input.shift().split(" ").map(Number);
let s = new Set(arr);
let s_arr = [...s].sort((a, b) => a - b);
let answer = [];

let bs = (arr, target) => {
  let st = 0;
  let en = arr.length - 1;
  while (st <= en) {
    let mid = Math.floor((st + en) / 2);
    if (arr[mid] < target) st = mid + 1;
    else if (arr[mid] > target) en = mid - 1;
    else return mid;
  }
  return -1;
};

for (let i = 0; i < n; i++) {
  answer.push(bs(s_arr, arr[i]));
}

console.log(answer.join(" "));
