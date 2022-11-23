let rotate = (s) => {
  let n = s.length;
  let m = s[0].length;
  let r = Array.from(Array(m), () => Array(n).fill(0));

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      r[j][n - i - 1] = s[i][j];
    }
  }

  return r;
};

let search = (s) => {
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (isAvailable(s, i, j)) return { ok: true, x: i, y: j };
    }
  }
  return { ok: false };
};

let isAvailable = (s, x, y) => {
  let r = s.length;
  let c = s[0].length;

  for (let i = 0; i < r; i++) {
    for (let j = 0; j < c; j++) {
      if (x + i >= n || y + j >= m) return false;
      if (board[x + i][y + j] === 1 && s[i][j] === 1) return false;
    }
  }
  return true;
};

let [...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

let [n, m, k] = input.shift().split(" ").map(Number);
let board = Array.from(Array(n), () => Array(m).fill(0));

while (k--) {
  let [r, c] = input.shift().split(" ").map(Number);
  let s = input.splice(0, r).map((v) => v.split(" ").map(Number));
  let a = search(s);
  let cnt = 4;
  while (cnt--) {
    if (a.ok === true) {
      for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
          board[a.x + i][a.y + j] = board[a.x + i][a.y + j]
            ? board[a.x + i][a.y + j]
            : s[i][j];
        }
      }
      break;
    }
    s = rotate(s);
    r = s.length;
    c = s[0].length;
    a = search(s);
  }
}

let answer = 0;

for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (board[i][j] === 1) answer++;
  }
}

console.log(answer);
