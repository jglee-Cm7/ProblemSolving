import heapq
n = int(input())
heap = []
for _ in range(n):
    for i in map(int, input().split()):
        heapq.heappush(heap, i)
        if len(heap) > n:
            heapq.heappop(heap)
print(heap[0])
