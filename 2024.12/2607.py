import copy
import math
import queue
import sys
from collections import Counter
import itertools

n = int(input())
word = [input() for _ in range(n)]
ans = 0
first = dict(Counter(word[0]))


for i in range(1, n):
    temp = dict(Counter(word[i]))
    res = {}
    res2 = {}

    for key in first.keys():
        if not key in temp.keys():
            res.update({key: first[key]})
        elif key in temp.keys():
            if abs(first[key] - temp[key]) <= 0: continue

            if first[key] > temp[key]: res.update({key:abs(first[key] - temp[key])})
            elif first[key] < temp[key]: res2.update({key:abs(first[key] - temp[key])})

    for key in temp.keys():
        if not key in first.keys():
            res2.update({key:temp[key]})

    if abs(sum(res.values()) - len(res2.values())) >= 2: continue
    elif sum(res.values()) + sum(res2.values()) > 2: continue



    ans += 1

print(ans)
