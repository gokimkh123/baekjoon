import sys
import math

a = input()
ans = 10

for i in range(1, len(a)):
    if a[i] != a[i-1]: ans +=  10
    else: ans += 5

print(ans)
