//난이도 : 실버 3, 유형 : dp

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

int dp[302];
int score[302];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int sum = 0;
    int n;cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> score[i];
        sum += score[i];
    }

    dp[1] = score[1],dp[2] = score[2],dp[3] = score[3];

    for(int i=4;i<=n-1;i++){
        dp[i] = min(dp[i-2],dp[i-3]) + score[i];
    }

    cout << sum - min(dp[n-1],dp[n-2]);
}

