import sys
import heapq

heap = []
n = int(input())
for _ in range(n):
  v = int(sys.stdin.readline())
  if v != 0:
    heapq.heappush(heap, (abs(v), v))
  else:
    if heap:
      print(heapq.heappop(heap)[1])
    else:
      print(0)