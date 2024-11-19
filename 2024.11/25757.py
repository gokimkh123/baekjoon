import math
import sys

n, game = map(str, sys.stdin.readline().split())
player =len(set(input().rstrip()for _ in range(int(n))))
dic_game = {'Y' : 1, 'F' : 2, 'O' : 3}

print(int(player / dic_game[game]))
