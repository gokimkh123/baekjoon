//난이도 : 골드3, 유형 : 파라미터 서치, 수학

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef tuple<int,int,int> tu;
typedef vector<int> vc;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    long double a, b, c;

    cin >> a >> b >> c;

    long double st = (c - b) / a, en = (c + b) / a;
    long double mid;
    int cnt = 50000;

    while(en - st > 0 && cnt--){
        mid = (st + en) / 2;
        long double val = (c - b * (long double)sin(mid)) / a;

        if(mid > val) en = mid;
        else if(mid < val) st = mid + 0.00000000000000000001;
    }

    printf("%.19Lf",mid);

}
/*
 Ax + Bsin(x) = C
 C - Bsin(x) = Ax
 (C - Bsin(x)) / A = x

 max = (C + B) / A, min = (C - B) / A
 */

