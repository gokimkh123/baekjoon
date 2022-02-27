//난이도 : 실버2, 유형 : 누적합

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

int num[5200];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,k,q,m;cin >> n >> k >> q >> m;

    for(int i=3;i<=n+2;i++) num[i] = 1; //출석 x

    for(int i=1;i<=k;i++){
        int a;cin >> a;num[a] = 2;      // 출석 x
    }

    for(int i=0;i<q;i++){
        int a;cin >> a;
        if(num[a] == 2) continue;
        for(int j=a;j<=n+2;j+=a){
            if(num[j] == 2) continue;
            num[j] = 3; // 3 출석완료
        }
    }

    int dp[50002];

    for(int i=3;i<=n+2;i++){
        if(num[i] == 3) dp[i] += dp[i-1] + 0;
        else if(num[i] == 2 || num[i] == 1) dp[i] += dp[i-1] + 1;
    }

    for(int i=0;i<m;i++){
        int s,e;
        cin >> s >> e;

        cout << dp[e] - dp[s-1] << "\n";
    }
}
