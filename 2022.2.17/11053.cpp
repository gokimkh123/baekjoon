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

int dp[1001],num[1001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,ans = 0;cin >> n;

    for(int i=0;i<n;i++){
        cin >> num[i];
        dp[i] = 1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(num[i] > num[j]) dp[i] = max(dp[i],dp[j]+1);
        }
    }

    for(int i=0;i<n;i++)
        ans = max(ans,dp[i]);

    cout << ans;
}

