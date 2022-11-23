let n = Number(require("fs").readFileSync("/dev/stdin").toString().trim());
let board = Array.from(Array(n), () => Array(n).fill(" "));
let a = (n, x, y) => {
  if (n === 3) {
    for (let i = 0; i < n; i++) {
      for (let j = 0; j < n; j++) {
        board[x + i][y + j] = "*";
      }
    }
    board[x + 1][y + 1] = " ";
    return;
  }

  let nn = n / 3;
  a(nn, x, y);
  a(nn, x, y + nn);
  a(nn, x, y + nn * 2);
  a(nn, x + nn, y);
  a(nn, x + nn, y + nn * 2);
  a(nn, x + nn * 2, y);
  a(nn, x + nn * 2, y + nn);
  a(nn, x + nn * 2, y + nn * 2);
};

a(n, 0, 0);
console.log(board.map((x) => x.join("")).join("\n"));
