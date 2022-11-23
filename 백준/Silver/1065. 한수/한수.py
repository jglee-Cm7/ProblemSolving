def han(n):
    if n < 10:
        return True
    a = list(map(int, list(str(n))))
    dif = a[1] - a[0]
    for i in range(2, len(a)):
        if (a[i] - a[i-1]) != dif:
            return False
    return True
        

n = input()
sum = 0
for x in range(1, int(n) + 1):
    if han(x) == True:
        sum += 1
print(sum)
