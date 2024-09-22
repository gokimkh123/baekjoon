import sys
import math

T = int(input())

for i in range(0, T):
    C = list(map(str, sys.stdin.readline().split()))
    A = float(C[0])

    for j in range(1, len(C)):
        if C[j] == '@' : A *= 3.0
        elif C[j] == '%' : A += 5.0
        else : A -= 7.0

    print('{:.2f}'.format(A))
