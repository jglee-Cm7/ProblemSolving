def makeBig(num, n, k):
    s = []
    for i in range(n):
        if len(s) == 0 or k == 0:
            s.append(num[i])
        else:
            while len(s) != 0 and int(s[-1]) < int(num[i]) and k > 0:
                s.pop()
                k -= 1
            s.append(num[i])

    while k != 0:
        s.pop()
        k -= 1
    
    result = int("".join(s))
    return result

def main():
    n, k = list(map(int, input().split()))
    num = input()
    result = makeBig(num, n, k)

    print(result)


if __name__ == "__main__":
    main()