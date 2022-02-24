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
#define mod
using namespace std;

l dp[41],vip[41],ans = 1;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,m;cin >> n >> m;

    for(int i=0;i<m;i++)
        cin >> vip[i];

    dp[0] = dp[1] = 1, dp[2] = 2;

    for(int i=3;i<=n;i++)
        dp[i] = dp[i-1] + dp[i-2];

    l start = 0;

    for(int i=0;i<m;i++){
        l end = vip[i];
        ans *= dp[end-start-1];
        start = end;
    }

    cout << ans * dp[n-start];

}

