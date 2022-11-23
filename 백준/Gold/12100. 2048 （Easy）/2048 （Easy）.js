let [...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

let n = Number(input.shift());
let board = input.map((v) => v.split(" ").map(Number));
let s = [];

let push = (board, d) => {
  let result = [];
  let rotateBoard = Array.from(Array(n), () => Array(n).fill(0));
  let rotateResult = Array.from(Array(n), () => Array(n).fill(0));

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (d === 0) rotateBoard[i][j] = board[i][j];
      if (d === 1) rotateBoard[n - 1 - j][i] = board[i][j];
      if (d === 2) rotateBoard[i][n - 1 - j] = board[i][j];
      if (d === 3) rotateBoard[j][n - 1 - i] = board[i][j];
    }
  }

  for (let i = 0; i < n; i++) {
    let row = [];
    let z = 0;
    for (let j = 0; j < n; j++) {
      if (rotateBoard[i][j] === 0) {
        z++;
        continue;
      }

      if (s.length === 0) {
        s.push(rotateBoard[i][j]);
      } else {
        if (s[s.length - 1] === rotateBoard[i][j]) {
          row.push(s.pop() * 2);
          z++;
        } else {
          row.push(s.pop());
          s.push(rotateBoard[i][j]);
        }
      }
    }

    while (s.length) row.push(s.pop());
    while (z--) row.push(0);

    result.push(row);
  }

  return result;
};

let mx = 0;
for (let i = 0; i < 1024; i++) {
  let f = i.toString(4);
  if (f.length < 5) f = "0".repeat(5 - f.length) + f;
  let c = [...f];

  let b = push(board, Number(c[0]));
  for (let i = 1; i < 5; i++) {
    b = push(b, Number(c[i]));
  }

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      mx = b[i][j] > mx ? b[i][j] : mx;
    }
  }
}

console.log(mx);
