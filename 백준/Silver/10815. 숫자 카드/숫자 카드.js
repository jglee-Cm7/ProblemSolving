let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let card = input[1].split(" ").map(Number);
let check = input[3].split(" ").map(Number);
card.sort((a, b) => a - b);
let bs = (arr, target) => {
  let st = 0;
  let en = arr.length - 1;
  while (st <= en) {
    let mid = ~~((st + en) / 2);
    if (arr[mid] < target) st = mid + 1;
    else if (arr[mid] > target) en = mid - 1;
    else return mid;
  }
  return -1;
};
console.log(check.map((v) => (bs(card, v) === -1 ? 0 : 1)).join(" "));