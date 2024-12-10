import math
import sys
from collections import Counter
import itertools

N, K = map(int, sys.stdin.readline().split())
board = list(input())
ans = 0


for i in range(N):
    if board[i] == 'P':
        for j in range(i - K, i + K + 1):
            if j >= N or j < 0 : continue

            if board[j] == 'H':
                board[j] = 'X'
                ans += 1
                break
print(ans)
