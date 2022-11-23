import math
def expandTri(t):
    es = " "*math.ceil(len(t[0]) / 2)       # empty space 생성
    ut = list(map(lambda t: es+t+es, t))    # upper T 생성
    lt = list(map(lambda t: t+" "+t, t))    # lower T 생성
    return ut+lt

n = input()
i = int(math.log2(int(n)//3))
t = ["  *  " , " * * ", "*****"]
for n in range(i):
    t = expandTri(t)

for n in range(len(t)):
    print(t[n])
