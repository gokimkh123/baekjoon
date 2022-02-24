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

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int cnt = 1;

    while(1){
        int n;cin >> n;
        if(!n) return 0;
        l dp[n+1][4];

        fill(&dp[1][1],&dp[n][3],0);

        for(int i=1;i<=n;i++)
           cin >> dp[i][1] >> dp[i][2] >> dp[i][3];


        dp[1][1] = 1000001,dp[1][3] += dp[1][2];

        for(int i=2;i<=n;i++){
            dp[i][1] += min(dp[i-1][1],dp[i-1][2]);
            dp[i][2] += min({dp[i-1][1],dp[i-1][2],dp[i-1][3],dp[i][1]});
            dp[i][3] += min({dp[i-1][2],dp[i-1][3],dp[i][2]});
        }

        cout << cnt++ << ". " << dp[n][2] << "\n";
    }

}

