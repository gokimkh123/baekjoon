//난이도 : 골드5, 유형 : dp

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define mod
using namespace std;

int dp[101][100001],w[101],v[101];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;

    for(int i=1;i<=n;i++)
        cin >> w[i] >> v[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(w[i] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]] + v[i]);
        }
    }

    cout << dp[n][k];
}
