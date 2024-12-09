import math
import sys
from collections import Counter
import itertools

N = input()
n = 0
idx = 0
while True:
    n += 1
    for s in str(n):
        if N[idx] == s:
            idx += 1
            if idx >= len(N):
                print(n)
                exit()
