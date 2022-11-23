let compare = (a, b) => a > b;

let heappush = (heap, v) => {
  heap.push(v);
  let idx = heap.length - 1;
  while (idx > 0) {
    let p = ~~((idx + 1) / 2) - 1;
    if (compare(heap[p], heap[idx])) [heap[p], heap[idx]] = [heap[idx], heap[p]];
    idx = p;
  }
};

let heappop = (heap) => {
  if (heap.length < 2) return heap.pop();
  let v = heap[0];
  heap[0] = heap.pop();
  p = 0;
  while (p * 2 + 1 < heap.length) {
    let left = p * 2 + 1,
      right = p * 2 + 2 < heap.length ? p * 2 + 2 : undefined;
    let target = right && compare(heap[left], heap[right]) ? right : left;
    if (!compare(heap[p], heap[target])) break;
    [heap[target], heap[p]] = [heap[p], heap[target]];
    p = target;
  }
  return v;
};

let [n, ...input] = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n").map(Number);
let heap = [];
let answer = 0;
for (let i = 0; i < n; i++) heappush(heap, input[i]);
while (heap.length > 1) {
  let s = heappop(heap) + heappop(heap);
  heappush(heap, s);
  answer += s;
}
console.log(answer);
