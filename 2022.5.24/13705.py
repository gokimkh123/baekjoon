#난이도 : 다이아4, 유형 : 임의 정밀도 / 큰 수 연산, 이분탐색

from decimal import *
import math

getcontext().prec = 50
PI = Decimal('3.14159265358979323846264338327950288419716939937510')
a,b,c = map(Decimal,input().split())

def sin_taylor(x):
    x = x % (2 * PI)
    p,n,end = 0,0,-1

    while(p != end):
        end = p
        p += Decimal(((-1)**n)*(x**(2*n+1)))/(Decimal(math.factorial(2*n+1)))
        n += 1

    return p

MAX,MIN = (c + b) / a,(c - b) / a
mid = 0

while MAX - MIN > Decimal(1e-21):
    mid = (MAX + MIN) / 2

    if(a*mid + b*sin_taylor(mid) < c): MIN = mid
    else : MAX = mid

print(round(mid,6))
