let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let [n, m] = input.shift().split(" ").map(Number);

let arr = input.map((v) => v.split(" ").map(Number));
let vis = Array.from(Array(n), () => Array(m).fill(0));
let dx = [0, 1, 0, -1];
let dy = [1, 0, -1, 0];

let s = [];
let answer = 0;
let t = 0;
while (1) {
  let area = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (arr[i][j] === 0 || vis[i][j] > 0) continue;
      s.push({ x: i, y: j });
      vis[i][j] = 1;
      area++;

      while (s.length > 0) {
        let cur = s.pop();

        for (let dir = 0; dir < 4; dir++) {
          let nx = cur.x + dx[dir];
          let ny = cur.y + dy[dir];

          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (arr[nx][ny] === 0 && vis[nx][ny] === 0)
            arr[cur.x][cur.y] += arr[cur.x][cur.y] ? -1 : 0;
          if (arr[nx][ny] === 0 || vis[nx][ny] > 0) continue;
          s.push({ x: nx, y: ny });
          vis[nx][ny] = vis[cur.x][cur.y] + 1;
        }
      }
    }
  }

  if (area > 1) {
    answer = t;
    break;
  }

  let mx = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      vis[i][j] = 0;
      mx = arr[i][j] > mx ? arr[i][j] : mx;
    }
  }
  if (mx === 0) break;
  t++;
}

console.log(answer);
