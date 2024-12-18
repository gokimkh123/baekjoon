import sys


n, m = map(int, sys.stdin.readline().split())

memo = {}
ans = n

for _ in range(n):
    a = input()
    memo[a] = 1

for _ in range(m):
    S = list(sys.stdin.readline().rstrip().split(','))

    for i in range(len(S)):
            if S[i] not in memo.keys():
                continue

            if memo[S[i]] == 1:
                memo.pop(S[i], None)
                ans -= 1
    print(ans)


