//난이도 : 실버1, 유형 : 경로추적, dp

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

int dp[1000001],route[1000001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;cin >> n;

    dp[1] = 0;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + 1;
        route[i] = i-1;
        if(i % 3 == 0 && dp[i] > dp[i/3] + 1){
            dp[i] = dp[i/3] + 1;
            route[i] = i / 3;
        }
        if(i % 2 == 0 && dp[i] > dp[i/2] + 1){
            dp[i] = dp[i/2] + 1;
            route[i] = i / 2;
        }
    }
    cout << dp[n] << "\n";

    int cur = n;
    while(1){
        cout << cur << " ";
        if(cur == 1) return 0;
        cur = route[cur];
    }
}

