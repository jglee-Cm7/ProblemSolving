
let bs = (arr, target) => {
  let st = 0;
  let en = arr.length - 1;
  while (st <= en) {
    let mid = Math.floor((st + en) / 2);
    if (arr[mid] < target) st = mid + 1;
    else if (arr[mid] > target) en = mid - 1;
    else return target;
  }
  return -1;
};

let [n, ...arr] = require("fs").readFileSync("/dev/stdin").toString().trim().split(/\s/).map(Number);

let arr2 = [];

for (let i = 0; i < n; i++) {
  for (let j = 0; j < n; j++) {
    arr2.push(arr[i] + arr[j]);
  }
}

arr2.sort((a, b) => a - b);

let mx = 0;
for (let i = 0; i < n; i++) {
  for (let j = 0; j < n; j++) {
    let value = bs(arr2, arr[i] - arr[j]);
    if (value !== -1) mx = value + arr[j] > mx ? value + arr[j] : mx;
  }
}

console.log(mx);
