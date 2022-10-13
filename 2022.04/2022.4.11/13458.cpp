//난이도 : 브론즈2, 유형 : 수학

#include <bits/stdc++.h>
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef vector<l> vc;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    l ans = 0,n,b,c;

    cin >> n;

    vc v(n);

    for(auto &i : v)
        cin >> i;

    cin >> b >> c;

    for(auto &i : v){
        ans++, i -= b;

        if(i > 0) i % c == 0 ? ans += (i / c) : ans += (i / c + 1);
    }

    cout << ans;

}

