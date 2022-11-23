let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let [n, m] = input.shift().split(" ").map(Number);
let city = input.map((v) => v.split(" ").map(Number));
let h = [];
let c = [];
let combi = [];

for (let i = 0; i < n; i++) {
  for (let j = 0; j < n; j++) {
    if (city[i][j] === 1) h.push({ x: i, y: j });
    if (city[i][j] === 2) c.push({ x: i, y: j });
  }
}

for (let i = 0; i < 1 << c.length; i++) {
  let cases = i.toString(2);
  cases = "0".repeat(c.length - cases.length) + cases;
  let ac = [...cases];
  if (ac.filter((x) => x === "1").length === m) combi.push(ac.map(Number));
}

let mn = (n - 1) * 2 * h.length;
for (let k = 0; k < combi.length; k++) {
  let tot = 0;
  for (let i = 0; i < h.length; i++) {
    let md = (n - 1) * 2;
    for (let j = 0; j < c.length; j++) {
      if (combi[k][j] === 0) continue;
      let dx = Math.abs(c[j].x - h[i].x);
      let dy = Math.abs(c[j].y - h[i].y);
      let d = dx + dy;
      md = md < d ? md : d;
    }
    tot += md;
  }
  mn = mn < tot ? mn : tot;
}
console.log(mn);
