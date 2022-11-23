let arr = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n").slice(1).map((v) => +v);
let d = [[0, 0, 0],[arr[0], 0, 0]];
for (let i = 1; i < arr.length; i++) d.push([Math.max(...d[i - 1]) + arr[i], d[i][0] + arr[i], Math.max(...d[i])]);
console.log(Math.max(...d.flat()));
