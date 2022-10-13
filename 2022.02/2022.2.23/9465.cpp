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

    int t;cin >> t;

    while(t--){
        int n;cin >> n;

        int dp[3][n],arr[3][n];

        for(int i=0;i<2;i++){
            for(int j=1;j<=n;j++)
                cin >> arr[i][j];
        }
        dp[0][0] = dp[1][0] = 0;
        dp[0][1] = arr[0][1], dp[1][1] = arr[1][1];

        for(int i=2;i<=n;i++){
            dp[0][i] = max(dp[1][i-1],dp[1][i-2]) + arr[0][i];
            dp[1][i] = max(dp[0][i-1],dp[0][i-2]) + arr[1][i];
        }
        cout << max(dp[0][n],dp[1][n]) << "\n";
    }

}

