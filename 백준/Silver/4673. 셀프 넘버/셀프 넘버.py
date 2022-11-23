def selfN(n):
    result = n
    while n:
        result += n % 10
        n = int(n / 10)
    return result
    
ch = [1]*10000

for n in range(1,10000):
    if ch[n] == 1:
        print(n)
        s = n
        while selfN(s) < 10000:
            s = selfN(s)
            ch[s] = 0
