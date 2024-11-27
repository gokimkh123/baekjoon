import math
import sys
from collections import Counter
import itertools

N, X = map(int, sys.stdin.readline().split())
People = list(map(int, sys.stdin.readline().split()))
now = sum(People[:X])
ans = [now]

for i in range(X, N):
    now = now + People[i] - People[i - X]
    ans.append(now)

print("SAD") if max(ans) == 0 else print(max(ans), ans.count(max(ans)), sep='\n')

