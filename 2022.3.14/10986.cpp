//난이도 : 골드3, 유형 : 수학, 누적합

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

l dp[1000001];
vector<l> check;

// 등차 수열 합? n(n-1)/2

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    l n,m,ans = 0;
    cin >> n >> m;

    vector<l> v(n+1);

    for(int i=1;i<=n;i++){
        cin >> v[i];
        dp[i] = dp[i-1] + v[i];
        if(dp[i] % m == 0) ans++;
        check.push_back(dp[i] % m);
    }

    sort(check.begin(),check.end());

    l cnt = 1;

    for(int i=0;i<n-1;i++){
        if(check[i] != check[i+1]){
            ans += (cnt * (cnt - 1) / 2);
            cnt = 1;
        }
        else cnt++;
    }
    ans += (cnt * (cnt - 1) / 2);
    cout << ans;
}

