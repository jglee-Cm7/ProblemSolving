a, b, n, *arr = map(int, open(0).read().split())
print(min(*map(lambda x: abs(x-b) + 1, arr), abs(b-a)))