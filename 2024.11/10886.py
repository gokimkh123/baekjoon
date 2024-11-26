import math
import sys
from collections import Counter

N = int(input())
a = list(input().rstrip() for _ in range(N))

ans = Counter(a)

print('Junhee is not cute!') if ans['0'] >= ans['1'] else print('Junhee is cute!')
