//난이도 : 골드4, 유형 : dp, 경로추적

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

int dp[1001],num[1001],route[1001];

void solve(int a){
    if(a == -1) return;
    solve(route[a]);

    cout << num[a] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int ans = 1,idx = 0;
    int n;cin >> n;

    for(int i=0;i<n;i++){
        cin >> num[i];
        dp[i] = 1;
    }

    fill(route,route+n,-1);

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(num[i] > num[j]){
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    route[i] = j;
                }
            }
        }
        if(ans < dp[i]){
            ans = dp[i];
            idx = i;
        }
    }

    cout << ans << "\n";

    solve(idx);
}

