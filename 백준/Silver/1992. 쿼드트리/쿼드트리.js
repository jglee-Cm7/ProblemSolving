let [n, ...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

let board = input.map((x) => [...x].map(Number));
let answer = "";

let check = (n, x, y, v) => {
  let result = 1;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (v !== board[x + i][y + j]) return 0;
    }
  }

  return result;
};

let r = (n, x, y) => {
  let v = board[x][y];
  if (check(n, x, y, v)) {
    answer += String(board[x][y]);
    return;
  }

  answer += "(";
  let h = n / 2;
  r(h, x, y);
  r(h, x, y + h);
  r(h, x + h, y);
  r(h, x + h, y + h);
  answer += ")";
};

r(Number(n), 0, 0);
console.log(answer);
