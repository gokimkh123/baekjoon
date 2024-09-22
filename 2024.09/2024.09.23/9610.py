import sys
import math

ans = {'Q1' : 0, 'Q2' : 0, 'Q3' : 0, 'Q4' : 0, 'AXIS' : 0}

n = int(input())

for i in range(0, n):
    a, b = map(int, sys.stdin.readline().split())

    if a == 0 or b == 0: ans['AXIS'] += 1
    elif a > 0 and b > 0: ans['Q1'] += 1
    elif a < 0 and b > 0: ans['Q2'] += 1
    elif a < 0 and b < 0: ans['Q3'] += 1
    elif a > 0 and b < 0: ans['Q4'] += 1

print('Q1: {}'.format(ans['Q1']))
print('Q2: {}'.format(ans['Q2']))
print('Q3: {}'.format(ans['Q3']))
print('Q4: {}'.format(ans['Q4']))
print('AXIS: {}'.format(ans['AXIS']))

