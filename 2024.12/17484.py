import copy
import math
import queue
import sys
from collections import Counter
import itertools

n, m = map(int, sys.stdin.readline().split())
board = [list(map(int, input().strip().split())) for _ in range(n)]
ans = 100 * 100 * 100
rx = [1, 1, 1]; ry = [-1, 0, 1]

def bfs(stX, stY, temp):
    global n, m
    res = 100 * 100 * 100
    q = queue.Queue()
    q.put([stX, stY, 0, temp[stX][stY]])
    temp[stX][stY] = -1
    while not q.empty():
        dx, dy, on, SUM = q.get()
        if dx == n - 1:
            res = min(res, SUM)
        for i in range(3):
            if on == 1 and i == 0: continue
            elif on == 2 and i == 1: continue
            elif on == 3 and i == 2: continue

            nx = dx + rx[i];ny = dy + ry[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue

            sw = 0
            if i == 0: sw = 1
            elif i == 1: sw = 2
            elif i == 2: sw = 3

            q.put([nx, ny, sw, temp[nx][ny] + SUM])

    return res


for i in range(m):
    ans = min(ans, bfs(0, i, copy.deepcopy(board)))

print(ans)
