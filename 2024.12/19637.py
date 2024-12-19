import sys
from bisect import bisect_left, bisect_right

n, m = map(int, sys.stdin.readline().split())

c = []
temp = {}
idx = 0

for i in range(n):
    a = list(map(str, sys.stdin.readline().split()))

    if a[1] in temp.keys(): continue

    temp[idx] = a[0]
    idx += 1
    c.append(int(a[1]))


sorted(c)

for _ in range(m):
    a = int(sys.stdin.readline().rstrip())

    print(temp[bisect_left(c, a)])






