from sys import stdin
import math
for pay in map(int, stdin.read().split()):
    if pay == 0:
        print(1)
        continue
    digits = int(math.log10(pay)) + 1
    for n in range(digits, 0, -1):
        if pay >= int(str(((10**n) - 1)).replace('9', '1')):
            print(n)
            break