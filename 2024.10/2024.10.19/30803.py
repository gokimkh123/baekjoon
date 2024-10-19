import sys

n = int(input())
A = list(map(int, sys.stdin.readline().split()))
Q = int(input())
toggle = [1] * (n + 1)

resSum = sum(A)
print(resSum)

while Q:
    q = list(map(int, sys.stdin.readline().split()))

    if q[0] == 1:

        if toggle[q[1] - 1] == 1:
            resSum -= A[q[1] - 1]
            A[q[1] - 1] = q[2]
            resSum += A[q[1] - 1]
        else:
            A[q[1] - 1] = q[2]

    else:
        # 토글 열때 resSum + A[q[1] - 1]
        if toggle[q[1] - 1] == 0:
            resSum += A[q[1] - 1]
            toggle[q[1] - 1] = 1

        # 토글 닫을때 resSum - A[q[1] - 1]
        elif toggle[q[1] - 1] == 1:
            resSum -= A[q[1] - 1]
            toggle[q[1] - 1] = 0

    print(resSum)
    Q -= 1


