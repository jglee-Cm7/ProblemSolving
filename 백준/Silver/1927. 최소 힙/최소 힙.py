import heapq
import sys
heap = []
n = int(input())
for _ in range(n):
    v = int(sys.stdin.readline())
    if v != 0:
        heapq.heappush(heap, v)
        continue
    if len(heap) == 0:
        print(0)
    else:
        print(heapq.heappop(heap))