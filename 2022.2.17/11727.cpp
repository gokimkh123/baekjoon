//난이도 : 실버3, 유형 : dp

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
l dp[1001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;cin >> n;

    dp[1] = 1, dp[2] = 3;
    for(int i=3;i<=n;i++) dp[i] = (dp[i-1] + dp[i-2] + dp[i-2]) % mod;

    cout << dp[n];

}

