// 난이도 : 실버3, 유형 : 수학, 그리디

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int, int> tu;
typedef vector<ll> vc;

vc a;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    ll n, temp, sum = 0, ans = 0, ma = 0;

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> temp;
        sum += temp;
        a.push_back(temp);
    }

    ll avg = sum / n;

    for(auto &i : a){
        if(avg - i >= 0) ans += avg - i;
        else ma++;
    }

    if(ma < (sum % n)) ans += (sum % n) - ma;
    cout << ans;
}
