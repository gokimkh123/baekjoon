# 난이도 : 실버5, 유형 : 정렬

import sys

n = sys.stdin.readline().rstrip()
n = int(''.join(sorted(n,reverse=True)))

print(-1) if n % 30 != 0 else print(n)


