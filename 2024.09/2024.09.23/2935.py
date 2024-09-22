import sys
import math

A = int(input())
Op = input()
B = int(input())

print(A + B if Op == '+' else A * B)
