import math
import sys
from collections import Counter

N, M = map(int, sys.stdin.readline().split())
book = list(input().rstrip() for _ in range(N))
book = [i for i in book if len(i) >= M]


book = Counter(book)
ans = {}
for i in book.keys():
    if i not in ans: ans[i] = [book[i], len(i), i]


ans = sorted(ans.values(), key=lambda x: (-x[0], -x[1], x[2]))

for i in ans:
    print(i[2])
