import math
import sys

N, score, P = map(int, sys.stdin.readline().split())

if N == 0:
    print(1)
    exit(0)

Rank = list(map(int, sys.stdin.readline().split()))

Rank.sort(reverse=True)

# 리스트 꽉 차 있을 때
if P == N and Rank[N - 1] >= score:
    print(-1)
else:
    Rank.append(score)
    Rank.sort(reverse=True)

    ans = 1

    for i in range(0, P):
        if Rank[i] == score:
            print(ans)
            break
            
        if i + 1 >= P or Rank[i + 1] == Rank[i]:
            continue

        ans = i + 2

