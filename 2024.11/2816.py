import math
import sys

n = int(input())
KBS1 = KBS2 = 0
ans = ''

for i in range(n):
    a = input()
    if a == 'KBS1': KBS1 = i
    elif a == 'KBS2': KBS2 = i

ans += '1' * KBS1 + '4' * KBS1


if KBS1 > KBS2:
    KBS2 += 1
ans += '1' * KBS2 + '4' * (KBS2 - 1)

print(ans)



