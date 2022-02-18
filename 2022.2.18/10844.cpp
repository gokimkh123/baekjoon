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

int mod = 1000000000;

l dp[101][101],ans;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;cin >> n;

    for(int i=1;i<=9;i++)
        dp[1][i] = 1;

    dp[1][0] = 0;

    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            if(j == 0) dp[i][j] = dp[i-1][j+1] % mod;
            else if(j == 9) dp[i][j] = dp[i-1][j-1] % mod;
            else dp[i][j] = dp[i][j] = (dp[i-1][j+1] + dp[i-1][j-1]) % mod;
        }
    }
    for(int i=0;i<=9;i++)
        ans += dp[n][i];

    cout << ans % mod;
}

