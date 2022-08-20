// 난이도 : 골드5, 유형 : 이분탐색

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

    int n;
    ll ans = 0;

    cin >> n;

    vc A(n);

    for(auto &i : A)
        cin >> i;

    sort(all(A));

    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            int sum = -1 * (A[i] + A[j]);

            auto a = lower_bound(A.begin() + j + 1, A.end(),sum);
            auto b = upper_bound(A.begin() + j + 1, A.end(), sum);

            ans += b - a;
        }
    }

    cout << ans;
}

