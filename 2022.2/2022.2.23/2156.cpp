//난이도 : 실버1, 유형 : dp

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

int dp[10001],num[10001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;cin >> n;

    for(int i=1;i<=n;i++)
        cin >> num[i];

    dp[1] = num[1],dp[2] = num[1] + num[2];

    for(int i=3;i<=n;i++)
        dp[i] = max({dp[i-1],dp[i-2] + num[i],dp[i-3] + num[i-1] + num[i]});

    cout << dp[n];
}

