//난이도 : 실버3, 유형 : dp, 누적합


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

int dp[100001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,m;cin >> n >> m;

    for(int i=1;i<=n;i++){
        int a;cin >> a;
        dp[i] = dp[i-1] + a;
    }

    while(m--){
        int i,j;cin >> i >> j;

        cout << dp[j] - dp[i-1] << "\n";
    }
}

