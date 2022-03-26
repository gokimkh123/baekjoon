난이도 : 골드4, 유형 : dp

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<int>
#define F first
#define S second
using namespace std;

int dp[1001][4],RGB[1001][4];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,ans = INF;
    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++)
            cin >> RGB[i][j];
    }

    for(int k=0;k<=2;k++){

        for(int i=0;i<=2;i++){
            if(i == k) dp[1][i] = RGB[1][i];
            else dp[1][i] = 1000 * 1000 + 1;
        }

        for(int i=2;i<=n;i++){
            dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + RGB[i][0];
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + RGB[i][1];
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + RGB[i][2];
        }

        for(int i=0;i<=2;i++){
            if(i == k) continue;
            ans = min(ans,dp[n][i]);
        }
    }

    cout << ans;
}

