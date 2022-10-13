// 난이도 : 실버1, 유형 : 수학, 정수론

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

    int m,n,x,y,t;
    cin >> t;

    while(t--) {
        cin >> m >> n >> x >> y;

        auto solve = [=](int m, int n, int x, int y){
            if(x == m) x = 0;
            if(y == n) y = 0;

            int end = lcm(m,n);
            for(int i=x;i<=end;i+=m){
                if(i == 0) continue;
                if(i % n == y) return i;
            }
            return -1;
        };

        cout << solve(m,n,x,y) << "\n";
    }
}
