let arr = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n").slice(1);
let s = new Set();
let answer = [];
for (let i = 0; i < arr.length; i++) {
  let [name, action] = arr[i].split(" ");
  if (action === "enter") s.add(name);
  else s.delete(name);
}
for (let key of s) answer.push(key);
console.log(answer.sort().reverse().join("\n"));
