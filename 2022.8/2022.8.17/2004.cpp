//난이도 : 실버2, 유형 : 수학

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

    auto Div = [](ll num, ll div){  // 5 * 2 = 10이므로 0이 된다. 따라서 5, 2의 개수들중 적은걸 선택
        ll cnt = 0;
        while(num){
            cnt += num / div;
            num /= div;
        }
        return cnt;
    };

    ll n, m;

    cin >> n >> m;

    // n! 0 개수 / {(n - m)! 0의 개수 + m! 0의 개수}

    ll Two = Div(n, 2) - Div(m,2) - Div((n - m), 2);
    ll Five = Div(n, 5) - Div(m, 5) - Div((n - m), 5);

    cout << min(Two, Five);
}

