// 난이도 : 실버 2, 유형 : 그리디, 정렬, 슬라이싱 윈도

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int, int> tu;
typedef vector<ll> vc;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    ll n, b, a, idx = 0, ans = 0, sum = 0;

    cin >> n >> b >> a;

    vc gift(n);

    for(auto &i : gift)
        cin >> i;

    sort(all(gift));

    for (int i = 0; i < n; i++) {
        sum += gift[i] / 2;

        if ((i + 1) > a) {
            sum = sum - gift[idx] / 2 + gift[idx];
            idx++;
        }
        if (sum <= b) ans = (i + 1);
    }

    cout << ans;
}
