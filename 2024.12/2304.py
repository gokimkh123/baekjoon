import sys

n = int(sys.stdin.readline())

temp = []
s = []
ans = 0

for i in range(n):
    l, h = map(int, sys.stdin.readline().split())

    temp.append([l, h])

temp.sort(key=lambda x: x[0])

maxL = temp[0][0]
maxH = temp[0][1]

for i in range(n):
    if temp[i][1] > maxH:
        ans += maxH * (temp[i][0] - maxL)
        maxH = temp[i][1]
        maxL = temp[i][0]

maxL = temp[-1][0]
maxH = temp[-1][1]

for i in range(n - 1, -1, -1):
    if temp[i][1] >= maxH:
        ans += maxH * abs(temp[i][0] - maxL)
        maxH = temp[i][1]
        maxL = temp[i][0]

print(maxH + ans)


