a = input()

while len(a) > 10:
    print(a[:10])
    a = a[10:]
print(a)