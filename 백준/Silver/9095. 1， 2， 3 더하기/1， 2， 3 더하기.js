let [_, ...arr] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let result = [1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504];
console.log(arr.map((v) => result[v - 1]).join("\n"));