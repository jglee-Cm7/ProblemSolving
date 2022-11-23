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

const [...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const [n, m] = input.splice(0, 1)[0].split(" ");
const board = input.map((v) => [...v].map(Number));
let vis = Array.from({ length: n }, (v, i) =>
  Array.from({ length: m }, (v, i) => 0)
);
const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];
let dist = 1;
const q = new Queue();
q.push({ x: 0, y: 0 });
vis[0][0] = dist;

// BFS
while (q.size() !== 0) {
  let cur = q.pop();
  for (let dir = 0; dir < 4; dir++) {
    let nx = cur.x + dx[dir];
    let ny = cur.y + dy[dir];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (vis[nx][ny] > 0 || board[nx][ny] === 0) continue;
    q.push({ x: nx, y: ny });
    vis[nx][ny] = vis[cur.x][cur.y] + 1;
  }
}
console.log(vis[n - 1][m - 1]);
