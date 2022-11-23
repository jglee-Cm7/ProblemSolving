let line = (board, x, y, d) => {
  let dx = [-1, 0, 1, 0];
  let dy = [0, 1, 0, -1];

  let nx = x + dx[d];
  let ny = y + dy[d];

  while (1) {
    if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] === 6) break;
    if (board[nx][ny] === 0) board[nx][ny] = -1;
    nx += dx[d];
    ny += dy[d];
  }
};

let [...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let [n, m] = input.shift().split(" ");
let board = input.map((x) => x.split(" ").map(Number));

let cam = [];
for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (board[i][j] > 0 && board[i][j] < 5) {
      cam.push({ c: board[i][j], x: i, y: j });
    }
    if (board[i][j] === 5) {
      line(board, i, j, 0);
      line(board, i, j, 1);
      line(board, i, j, 2);
      line(board, i, j, 3);
    }
  }
}

let arr = Array(cam.length).fill(0);
let combination = [];

let r = (k) => {
  if (k === cam.length) {
    combination.push([...arr]);
    return;
  }

  for (let i = 0; i < 4; i++) {
    if (cam[k].c === 2 && i > 1) continue;
    arr[k] = i;
    r(k + 1);
  }
};

r(0);

let min = 0;
for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (board[i][j] === 0) min++;
  }
}

for (let i = 0; i < combination.length; i++) {
  let tempBoard = board.map((v) => [...v]);
  for (let j = 0; j < combination[i].length; j++) {
    let { c, x, y } = cam[j];
    let d = combination[i][j];

    if (c === 1) line(tempBoard, x, y, d);
    if (c === 2) {
      line(tempBoard, x, y, d);
      line(tempBoard, x, y, (d + 2) % 4);
    }
    if (c === 3) {
      line(tempBoard, x, y, d);
      line(tempBoard, x, y, (d + 1) % 4);
    }
    if (c === 4) {
      line(tempBoard, x, y, d);
      line(tempBoard, x, y, (d + 1) % 4);
      line(tempBoard, x, y, (d + 2) % 4);
    }
  }

  let cnt = 0;
  for (let x = 0; x < n; x++) {
    for (let y = 0; y < m; y++) {
      if (tempBoard[x][y] === 0) cnt++;
    }
  }
  min = cnt < min ? cnt : min;
}

console.log(min);
