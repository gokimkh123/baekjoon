//난이도 : 실버3, 유형 : 재귀함수, dp

//재귀 풀이
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

vector<int> T;
vector<int> P;

int ans = -1,n;
void dfs(int num,int sum){
    if(num > n) return;

    ans = max(ans,sum);

    for(int i=num;i<n;i++)  dfs(i + T[i],sum + P[i]);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;

    for(int i=0;i<n;i++){
        int a,b;cin >> a >> b;T.push_back(a),P.push_back(b);
    }

    dfs(0,0);

    cout << ans;
}



//dp 풀이

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

int dp[20],T[20],P[20];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;cin >> n;

    for(int i=1;i<=n;i++)    cin >> T[i] >> P[i];

    for(int i=n;i>=1;i--){
        if(i + T[i] <= n + 1) dp[i] = max(dp[i+T[i]] + P[i], dp[i+1]);
        else dp[i] = dp[i+1];
    }

    cout << dp[1];
}

