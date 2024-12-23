import sys

p, m = map(int, sys.stdin.readline().split())

room = {}
temp = {}

for _ in range(p):
    l, n = sys.stdin.readline().split()
    l = int(l)

    if len(room) == 0:
        room[n] = [{l : n}]

    else:
        on = 1
        for i in room.keys():
            if len(room[i]) == m:
                continue
            elif -10 <= list(room[i][0].keys())[0] - l <= 10:
                room[i].append({l : n})
                on = 0
                break
        if on == 1:
            room[n] = [{l : n}]
    temp[n] = l



for i in room.keys():
    if len(room[i]) == m:
        print('Started!')
    elif len(room[i]) < m:
        print('Waiting!')


    ans = []
    for j in range(len(room[i])):
        t = list(room[i][j].values())[0]
        ans.append((temp[t], t))

    ans = sorted(ans, key=lambda x: x[1])

    for j in ans:
        print(j[0], j[1], sep=' ')



