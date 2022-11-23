n = int(input())

for i in range(n):
    s = input()
    s = list(map(int, list(s.replace('X', '0').replace('O', '1'))))

    for n in range(1, len(s)):
        if s[n] != 0: s[n] = s[n-1] + 1
    print(sum(s))
    
