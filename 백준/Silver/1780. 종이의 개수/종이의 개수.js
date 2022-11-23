let answer = [0, 0, 0];

const r = (n, x, y) => {
  if (n === 1) {
    answer[board[x][y] + 1]++;
    return;
  }

  let v = board[x][y];
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      // 9등분으로 나눔.
      if (v !== board[x + i][y + j]) {
        let nn = n / 3;
        for (let ni = x; ni < x + n; ni += nn) {
          for (let nj = y; nj < y + n; nj += nn) {
            r(nn, ni, nj);
          }
        }
        return;
      }
    }
  }

  // 다 같으면
  answer[v + 1]++;
  return;
};

let [n, ...arr] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

let board = arr.map((x) => x.split(" ").map(Number));

r(Number(n), 0, 0);
console.log(answer.join("\n"));