//난이도 : 실버1, 유형 : dp

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <deque>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,ans = -1;cin >> n;

   for(int i=1;i<=n;i++){
       for(int j=1;j<=i;j++)
           cin >> dp[i][j];
   }

   for(int i=2;i<=n;i++){
       for(int j=1;j<=i;j++){
           if(j == 1) dp[i][j] += dp[i-1][j];
           else if(j == i) dp[i][j] += dp[i-1][j-1];
           else dp[i][j] += max(dp[i-1][j-1],dp[i-1][j]);
       }
   }

   for(int i=1;i<=n;i++)
       ans = max(ans,dp[n][i]);

   cout << ans;
}

