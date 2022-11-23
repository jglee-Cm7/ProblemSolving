let [n, ...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

let board = input.map((x) => x.split(" ").map(Number));
let answer = [0, 0];

let check = (n, x, y, v) => {
  let result = 1;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (v !== board[x + i][y + j]) {
        return 0;
      }
    }
  }
  return result;
};

let r = (n, x, y) => {
  let v = board[x][y];
  if (check(n, x, y, v)) {
    answer[v]++;
    return;
  }
  let half = n / 2;

  r(half, x, y);
  r(half, x, y + half);
  r(half, x + half, y);
  r(half, x + half, y + half);
};

r(Number(n), 0, 0);

console.log(answer.join("\n"));