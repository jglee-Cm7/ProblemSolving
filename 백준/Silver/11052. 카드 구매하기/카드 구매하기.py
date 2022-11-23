# https://www.acmicpc.net/problem/11052


def getPayForMax(n, pn):
    result = []
    pn_len = len(pn)
    
    for i in range(1, n+1):
        candi = []
        candi.append(pn[i-1])
        for j in range(1, int((i/2)+1)):
            if i - j == 0:
                break
            candi.append(result[i-j-1] + result[j-1])
        result.append(max(candi))

    return result

def main():
    n = int(input())
    pn = [int(x) for x in input().split()]
    result = getPayForMax(n, pn)

    print(result[n-1])


if __name__ == "__main__":
    main()
