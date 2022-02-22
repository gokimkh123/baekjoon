//난이도 : 실버2, 유형 : dp

#include <iostream>
#include <vector>
#include <cmath>
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

l mod = 1000000009;
l dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;cin >> t;

    dp[1] = 1, dp[2] = 2, dp[3] = 4;

    for(int i=4;i<=1000000;i++)
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % mod;


    while(t--){
        int n;cin >> n;

        cout << dp[n] << "\n";
    }
}

