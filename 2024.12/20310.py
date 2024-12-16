import copy
import math
import queue
import sys
from collections import Counter
import itertools

S = list(input())
cnt = dict(Counter(S))
cnt = {i : int(cnt[i] / 2) for i in cnt.keys()}
Len = len(S)

for i in range(Len):
    if S[i] == '1' and cnt[S[i]] > 0:
        cnt[S[i]] -= 1
        S[i] = '-1'

    if S[Len - i - 1] == '0' and cnt[S[Len - i - 1]] > 0:
        cnt[S[Len - i - 1]] -= 1
        S[Len - i - 1] = '-1'

print(''.join([i for i in S if i != '-1']))
