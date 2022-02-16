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

int dp[1001][4],R[1001],G[1001],B[1001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;cin >> n;

    for(int i=1;i<=n;i++) cin >> R[i] >> G[i] >> B[i];

    dp[1][0] = R[1], dp[1][1] = G[1], dp[1][2] = B[1];

    for(int i=2;i<=n;i++){
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + R[i];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + G[i];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + B[i];
    }

    cout << min({dp[n][0],dp[n][1],dp[n][2]});
}

