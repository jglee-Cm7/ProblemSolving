from itertools import combinations

def getCount(pw):
    lower = ['a','e','i','o','u']
    v = 0 # 모음
    c = 0 # 자음
    for s in pw:
        if s in lower:
            v += 1
        else:
            c += 1
    
    return (v, c)

def makePw(l, alp):
    sorted_alp = sorted(alp)

    candi = []
    coms = list(combinations(sorted_alp, l))
    for com in coms:
         v, c = getCount(com)
         if v > 0 and c > 1:
             candi.append("".join(sorted(com)))

    print(*candi, sep='\n')
    



def main():
    l, c = list(map(int, input().split()))
    alp = input().split()

    makePw(l, alp)

if __name__ == "__main__":
    main()