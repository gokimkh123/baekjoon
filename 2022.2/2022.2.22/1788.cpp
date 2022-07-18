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

l mod = 1000000000;
l dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    dp[0] = 0,dp[1] = 1;

    int n;cin >> n;

    for(int i=2;i<=abs(n);i++)
        dp[i] = (dp[i-2] + dp[i-1]) % mod;


    if(n < 0 && n % 2 == 0) cout << "-1\n";
    else if(n == 0) cout << "0\n";
    else cout << "1\n";

    cout << dp[abs(n)] % mod;
}

