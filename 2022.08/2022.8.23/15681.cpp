// 난이도 : 골드5, 유형 : 트리 + dp

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tu;
typedef vector<int> vc;

int dp[100001];
vc tree[100001];

int dfs(int cur, int par){
    dp[cur] = 1;

    for(auto next : tree[cur]){
        if(next == par) continue;

        dp[cur] += dfs(next, cur);
    }

    return dp[cur];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n, r, q, u, v;

    cin >> n >> r >> q;

    for(int i=0;i<n-1;i++){
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(r, 0);

    while(q--){
        cin >> u;
        cout << dp[u] << "\n";
    }


}

