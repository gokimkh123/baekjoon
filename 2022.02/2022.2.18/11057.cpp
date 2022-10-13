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

int mod = 10007;

l dp[1001][1001],ans;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;cin >> n;

    for(int i=0;i<=9;i++)
        dp[1][i] = 1;

    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=j;k++){
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= mod;
            }
        }
    }
    for(int i=0;i<=9;i++)
        ans += dp[n][i];

    cout << ans % mod;
}

