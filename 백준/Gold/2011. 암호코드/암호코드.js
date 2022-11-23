let arr = [...require("fs").readFileSync("/dev/stdin").toString().trim()].reverse();
let d = Array(arr.length + 1).fill(1);
d[1] = arr[0] === "0" || arr.length === 0 ? 0 : 1;
for (let i = 1; i < arr.length; i++) {
  if (arr[i] === "0") d[i + 1] = 0;
  else d[i + 1] = Number(arr[i] + arr[i - 1]) < 27 ? d[i] + d[i - 1] : d[i];
  d[i + 1] %= 1000000;
}
console.log(d[d.length - 1]);
