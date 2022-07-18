//난이도 : 실버2, 유형 : dp

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

int dp[100001],num[100001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,ans = -1001;cin >> n;

    for(int i=1;i<=n;i++)
        cin >> num[i];

    for(int i=1;i<=n;i++)
        dp[i] = max(dp[i-1] + num[i],num[i]);

    for(int i=1;i<=n;i++)
        ans = max(ans,dp[i]);

    cout << ans;
}

