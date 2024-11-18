import math
import sys

T = int(input())

while T:
    T -= 1

    tall = list(map(int, sys.stdin.readline().split()))
    temp = tall[:]
    ans = 0


    for i in range(1, 21):
        for j in range(1, i):
            if tall[i] < tall[j]:
                a = tall[i]

                for k in range(i, j, -1):
                    tall[k] = tall[k - 1]
                    ans += 1

                tall[j] = a
                break

    print(temp[0], ans)
