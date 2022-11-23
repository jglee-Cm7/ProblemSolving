let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let dh = [0, 0, 0, 0, 1, -1];
let dx = [0, 1, 0, -1, 0, 0];
let dy = [1, 0, -1, 0, 0, 0];
let vis = Array.from(Array(30), () =>
  Array.from(Array(30), () => Array(30).fill(0))
);
let bd = Array.from(Array(30), () =>
  Array.from(Array(30), () => Array(30).fill(0))
);
let idx = 0;
while (1) {
  let q = [];
  let qIdx = 0;
  let [l, r, c] = input[idx++].split(" ").map(Number);
  if (l + r + c === 0) break;
  for (let i = 0; i < l; i++) {
    for (let j = 0; j < r; j++) {
      for (let k = 0; k < c; k++) vis[i][j][k] = 0;
    }
  }
  for (let i = 0; i < l; i++) {
    for (let j = 0; j < r; j++) {
      let row = input[idx++];
      for (let k = 0; k < row.length; k++) {
        bd[i][j][k] = row[k];
        if (row[k] === "S") {
          q.push({ h: i, x: j, y: k });
          vis[i][j][k] = 1;
        }
      }
    }
    idx++;
  }
  let flag = false;
  while (q.length > qIdx) {
    let cur = q[qIdx++];
    if (bd[cur.h][cur.x][cur.y] === "E") {
      console.log(`Escaped in ${vis[cur.h][cur.x][cur.y] - 1} minute(s).`);
      flag = true;
      break;
    }
    for (let dir = 0; dir < 6; dir++) {
      let nh = cur.h + dh[dir];
      let nx = cur.x + dx[dir];
      let ny = cur.y + dy[dir];
      if (nh < 0 || nh >= l || nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if (bd[nh][nx][ny] === "#") continue;
      if (vis[nh][nx][ny] > 0) continue;
      q.push({ h: nh, x: nx, y: ny });
      vis[nh][nx][ny] = vis[cur.h][cur.x][cur.y] + 1;
    }
  }
  if (!flag) console.log("Trapped!");
}
