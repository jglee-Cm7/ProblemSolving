let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let [n, m] = input.shift().split(" ").map(Number);
let memberMap = new Map();
let teamMap = new Map();
let answer = [];
while (n--) {
  let teamName = input.shift();
  let count = +input.shift();
  teamMap.set(
    teamName,
    input.splice(0, count).map((v) => {
      memberMap.set(v, teamName);
      return v;
    })
  );
}
while (m--) {
  let q = input.shift();
  let type = +input.shift();
  if (type) answer.push(memberMap.get(q));
  else answer.push(teamMap.get(q).sort());
}
console.log(answer.flat().join("\n"));
