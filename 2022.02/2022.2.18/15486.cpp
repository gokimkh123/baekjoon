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

l dp[2000000],T[2000000],P[2000000];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;cin >> n;

    for(int i=1;i<=n;i++)    cin >> T[i] >> P[i];

    for(l i=n;i>=1;i--){
        if(i + T[i] <= n + 1) dp[i] = max(dp[i+T[i]] + P[i], dp[i+1]);
        else dp[i] = dp[i+1];
    }

    cout << dp[1];
}

