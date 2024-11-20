import math
import sys

n = int(input())
dx = [-1, 1, 0, 0, 1]
dy = [0, 0, -1, 1, 0]

board = []
heart = ()

L = R = LL = RR = B = H = 0
Bx = By = 0

for _ in range(n):
    a = input()
    board.append(a)

def dfs(cnt, x, y, on):
    global Bx, By
    if x < 0 or x >= n or y < 0 or y >= n or board[x][y] == '_':
        if on == 4:
            Bx = x
            By = y
        return cnt

    return dfs(cnt + 1, x + dx[on], y + dy[on], on)

for i in range(n):
    for j in range(n):
        if board[i][j] == '-': continue
        if i - 1 < 0 or j - 1 < 0 or i + 1 >= n or j + 1 >= n: continue

        if board[i][j - 1] == board[i - 1][j] == board[i + 1][j] == board[i][j] == '*':
            heart = (i, j)

            L = dfs(-1, i, j, 2)
            R = dfs(-1, i, j, 3)
            B = dfs(-1, i, j, 4)
            LL = dfs(0, Bx, By - 1, 1)
            RR = dfs(0, Bx, By + 1, 1)
            break
    if L != 0: break

print(heart[0] + 1, heart[1] + 1)
print(L, R, B, LL, RR)
