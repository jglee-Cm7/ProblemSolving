
let [t, ...input] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

t = Number(t);
let dx = [-1, 0, 1, 0];
let dy = [0, 1, 0, -1];
let answer = [];

while (t--) {
  let [m, n] = input.shift().split(" ").map(Number);
  let map = input.splice(0, n).map((x) => [...x]);
  let fVis = Array.from(Array(n), () => Array(m).fill(-1));
  let sVis = Array.from(Array(n), () => Array(m).fill(-1));
  let qf = [];
  let qs = [];
  let qfIdx = 0;
  let qsIdx = 0;
  let result = "IMPOSSIBLE";

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (map[i][j] === "*") {
        qf.push({ x: i, y: j });
        fVis[i][j] = 0;
      }
      if (map[i][j] === "@") {
        qs.push({ x: i, y: j });
        sVis[i][j] = 0;
      }
    }
  }

  while (qf.length > qfIdx) {
    let cur = qf[qfIdx++];

    for (let dir = 0; dir < 4; dir++) {
      let nx = cur.x + dx[dir];
      let ny = cur.y + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (map[nx][ny] === "#" || map[nx][ny] === "*" || fVis[nx][ny] > -1)
        continue;
      fVis[nx][ny] = fVis[cur.x][cur.y] + 1;
      qf.push({ x: nx, y: ny });
    }
  }

  while (qs.length > qsIdx) {
    let cur = qs[qsIdx++];
    if (cur.x === 0 || cur.y === 0 || cur.x === n - 1 || cur.y === m - 1) {
      if (
        fVis[cur.x][cur.y] === -1 ||
        sVis[cur.x][cur.y] < fVis[cur.x][cur.y]
      ) {
        result = sVis[cur.x][cur.y] + 1;
        break;
      }
    }

    for (let dir = 0; dir < 4; dir++) {
      let nx = cur.x + dx[dir];
      let ny = cur.y + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (map[nx][ny] !== "." || sVis[nx][ny] > -1) continue;
      sVis[nx][ny] = sVis[cur.x][cur.y] + 1;
      qs.push({ x: nx, y: ny });
    }
  }

  answer.push(result);
}

console.log(answer.join("\n"));
