let n = Number(require("fs").readFileSync("/dev/stdin").toString().trim());

let used1 = Array(n).fill(0);
let used2 = Array((n - 1) * 2 + 1).fill(0);
let used3 = Array((n - 1) * 2 + 1).fill(0);
let arr = Array(n).fill(0);
let answer = [];

let r = (n, k) => {
  if (n === k) {
    answer.push(arr);
    return;
  }

  for (let i = 0; i < n; i++) {
    if (!used1[i] && !used2[k + i] && !used3[k - i + n - 1]) {
      arr[k] = i;
      used1[i] = 1;
      used2[k + i] = 1;
      used3[k - i + n - 1] = 1;

      r(n, k + 1);

      used1[i] = 0;
      used2[k + i] = 0;
      used3[k - i + n - 1] = 0;
    }
  }
};

r(n, 0);

console.log(answer.length);
