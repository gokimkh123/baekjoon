// 난이도: 실버 5, 유형 : 완전탐색

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tu;
typedef vector<int> vc;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int e, s, m, ee, ss , mm, ans = 1;
    e = s = m = 1;

    cin >> ee >> ss >> mm;

    while(1){
        if(ee == e && ss == s && mm == m){
            cout << ans;
            return 0;
        }

        ans++, e++, s++, m++;

        if(e > 15) e = 1;
        if(s > 28) s = 1;
        if(m > 19) m = 1;
    }
}

