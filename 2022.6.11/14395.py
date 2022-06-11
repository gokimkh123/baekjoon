# 난이도 : 골드5, 유형 : bfs

from collections import deque

s,t = map(int,input().split())
MAX = 10e9


def Bfs():
    check = set()
    q = deque([(s,'')])
    check.add(s)

    while q:
        cur, str = q.popleft()

        if cur == t:
            return str

        if cur * cur <= MAX and cur * cur not in check:
            q.append((cur * cur, str + '*'))
            check.add(cur * cur)

        if cur * 2 <= MAX and cur * 2 not in check:
            q.append((cur * 2, str + '+'))
            check.add(cur * 2)

        if 1 not in check:
           q.append((1, str + '/'))
           check.add(1)

    return -1

if s == t: print(0)
else : print(Bfs())



