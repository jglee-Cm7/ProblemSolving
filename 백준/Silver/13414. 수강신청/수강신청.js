let [...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let [k, l] = input[0].split(" ").map(Number);
let arr = input.slice(1);
let s = new Set();
for (let i = 0; i < l; i++) {
  if (s.has(arr[i])) {
    s.delete(arr[i]);
    s.add(arr[i]);
  } else {
    s.add(arr[i]);
  }
}
console.log([...s].slice(0, k).join("\n"));