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

int num[1001],n,dp[1001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;

    for(int i=1;i<=n;i++)
        cin >> num[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            dp[i] = max(dp[i],dp[i-j] + num[j]);
    }

    cout << dp[n];
}

