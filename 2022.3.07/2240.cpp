//난이도 : 골드5, 유형 : dp

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

int num[1001],dp[1001][31][3];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int T,W;

    cin >> T >> W;

    for(int i=1;i<=T;i++)
        cin >> num[i];

    for(int i=1;i<=T;i++){
        dp[i][0][1] = dp[i-1][0][1] + (num[i] == 1 ? 1 : 0);
        for(int j=1;j<=W;j++){
            if(i < j) break;
            if(num[i] == 1){
                dp[i][j][1] = max(dp[i-1][j-1][2],dp[i-1][j][1]) + 1;
                dp[i][j][2] = max(dp[i-1][j-1][1],dp[i-1][j][2]);
            }
            else{
                dp[i][j][1] = max(dp[i-1][j-1][2],dp[i-1][j][1]);
                dp[i][j][2] = max(dp[i-1][j-1][1],dp[i-1][j][2]) + 1;
            }
        }
    }

    int ans = 0;

    for(int i=0;i<=T;i++)
        ans = max({ans,dp[T][i][1],dp[T][i][2]});

    cout << ans;
}
