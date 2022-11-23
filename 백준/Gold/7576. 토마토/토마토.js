class Queue {
  constructor() {
    this.storage = {};
    this.front = 0;
    this.rear = 0;
  }

  size() {
    if (this.storage[this.rear] === undefined) {
      return 0;
    } else {
      return this.rear - this.rear + 1;
    }
  }

  push(value) {
    if (this.size() === 0) {
      this.storage["0"] = value;
    } else {
      this.rear += 1;
      this.storage[this.rear] = value;
    }
  }

  pop() {
    let temp;
    if (this.front === this.rear) {
      temp = this.storage[this.front];
      delete this.storage[this.front];
      this.front = 0;
      this.rear = 0;
    } else {
      temp = this.storage[this.front];
      delete this.storage[this.front];
      this.front += 1;
    }
    return temp;
  }

  peak() {
    return this.storage[this.front];
  }
}

let [...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let [m, n] = input.splice(0, 1)[0].split(" ").map(Number);
let board = input.map((v) => v.split(" ").map(Number));
let vis = board.slice(0);

let q = new Queue();
const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];
let max = 0;

for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (board[i][j] === 1) q.push({ x: i, y: j });
  }
}

while (q.size() !== 0) {
  let cur = q.pop();
  for (let dir = 0; dir < 4; dir++) {
    let nx = cur.x + dx[dir];
    let ny = cur.y + dy[dir];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (board[nx][ny] === -1 || vis[nx][ny] > 0) continue;
    q.push({ x: nx, y: ny });
    vis[nx][ny] = vis[cur.x][cur.y] + 1;
  }
  max = max > vis[cur.x][cur.y] ? max : vis[cur.x][cur.y];
}

const fail = vis.map((x) => x.some((y) => y === 0)).some((v) => v);
console.log(fail ? -1 : max - 1);
