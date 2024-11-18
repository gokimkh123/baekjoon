import math
import sys
H, W, N, M = map(int, sys.stdin.readline().split())

a = math.ceil(math.ceil(W/(M + 1)))
b = math.ceil(math.ceil(H/(N+ 1)))

print(a * b)
