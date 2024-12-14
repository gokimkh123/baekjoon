import copy
import math
import queue
import sys
from collections import Counter
import itertools

T = int(input())

ans = []

while T:
    T -= 1

    n, k, t, m = map(int ,sys.stdin.readline().split())

    score = []
    board = [[0] * k for _ in range(n)]
    time = [0] * n
    cnt = [0] * n

    for it in range(m):
        i, j, s = map(int, sys.stdin.readline().split())

        board[i - 1][j - 1] = max(board[i - 1][j - 1], s)
        time[i - 1] = it
        cnt[i - 1] += 1



    for i in range(len(board)):
        score.append([sum(board[i]), cnt[i], time[i], i + 1])

    res = sorted(score, key=lambda x:(-x[0], x[1], x[2]))

    for i in range(0, len(res)):
        if t == res[i][3]:
            ans.append(i + 1)
            break

for i in ans:
    print(i)



