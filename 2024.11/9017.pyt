import math
import sys
from collections import Counter

T = int(input())

while T:
    T -= 1

    N = int(input())

    player = list(map(int, sys.stdin.readline().split()))
    score = {}
    Count = Counter(player)

    rank = 1
    for i in range(N):
        if Count[player[i]] == 6:
            if player[i] in score:
                score[player[i]].append(rank)
            else:
                score[player[i]] = [rank]
            rank += 1

    print(sorted(score, key=lambda x: (sum(score[x][0:4]), score[x][4]))[0])


    

