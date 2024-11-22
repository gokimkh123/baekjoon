import math
import sys

N = int(input())
M = int(input())
x = list(map(int, sys.stdin.readline().split()))

first = x[0]
end = N - x[-1]
ans = max(first, end)

for i in range(M - 1):
    ans = max(ans, math.ceil(abs(x[i] - x[i + 1]) / 2))

print(ans)
