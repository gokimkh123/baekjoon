import sys

n = int(input())
fruits = list(map(int, sys.stdin.readline().split()))
countFruits = [0] * 11
res = cnt = lo = maxCnt = 0

for hi in range(n):
    countFruits[fruits[hi]] += 1

    if countFruits[fruits[hi]] == 1:
        cnt += 1


    while cnt > 2:
        countFruits[fruits[lo]] -= 1
        if countFruits[fruits[lo]] == 0:
            cnt -= 1
        lo += 1

    res = max(res, hi - lo + 1)

print(res)

