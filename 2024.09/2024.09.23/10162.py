import sys
import math

T = int(input())


ans = [0] * 3
ans[0] += T // 300; T %= 300
ans[1] += T // 60; T %= 60
ans[2] += T // 10; T %= 10

if T != 0: print('-1')
else: print(ans[0], ans[1], ans[2])
