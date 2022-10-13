// 난이도 : 골드4, 유형 : 트리, dp

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

void dfs(int cur, int par) {
    for (auto next: tree[cur]) {
        if (next == par) continue;
        dp[next] += dp[cur];
        dfs(next, cur);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n, m, superior, num, w;

    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> superior;
        if(i == 1) continue;

        tree[i].push_back(superior);
        tree[superior].push_back(i);
    }
    while(m--){
        cin >> num >> w;

        dp[num] += w;
    }

    dfs(1,-1);

    for(int i=1;i<=n;i++)
        cout << dp[i] << " ";
}

