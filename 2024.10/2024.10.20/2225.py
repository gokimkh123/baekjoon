import sys
import math
N, K = map(int, sys.stdin.readline().split())
memo = [[0] * (200 + 1)] * (200 + 1)
CONST_DIV = 1000000000
print(math.comb(K + N - 1, N) % CONST_DIV)

