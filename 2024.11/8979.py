import math
import sys

n, k = map(int, sys.stdin.readline().split())
country = []
rank = 1

for _ in range(n):
    a = list(map(int, sys.stdin.readline().split()))
    country.append(a)

ans = sorted(country, key=lambda x: (-x[1], -x[2], -x[3]))

for i in range(0, n):
    if ans[i][0] == k:
        print(rank)
        break

    if i + 1 >= n or ans[i][1] == ans[i + 1][1] and ans[i][2] == ans[i + 1][2] and ans[i][3] == ans[i + 1][3]:
        continue

    rank = i + 2

