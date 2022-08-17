// 난이도 : 실버4, 유형 : gcd

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

int Gcd(int a, int b){
    if(b == 0) return a;

    return Gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t, n;

    cin >> t;

    while(t--){
        ll ans = 0;

        cin >> n;

        vc v(n);

        for(auto &i : v)
            cin >> i;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
                ans += gcd(v[i], v[j]);
        }

        cout << ans << "\n";
    }
}

