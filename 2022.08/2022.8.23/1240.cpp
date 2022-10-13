// 난이도 : 골드5, 유형 : bfs

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tu;
typedef vector<pa> vc;

vc tree[1001];

int bfs(int st, int en){
    bool vis[10001] = {0, };
    int ans = 0;

    queue<pa> q;
    q.push({st, 0});
    vis[st] = true;

    while(!q.empty()){
        auto cur = q.front();q.pop();

        if(cur.F == en){
            ans = cur.S;
            break;
        }

        for(auto next : tree[cur.F]){
            if(next.F == cur.F || vis[next.F]) continue;

            vis[next.F] = true;
            q.push({next.F, next.S + cur.S});
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n, m, u, v, a;

    cin >> n >> m;

    for(int i=0;i<n-1;i++){
        cin >> u >> v >> a;

        tree[u].push_back({v,a});
        tree[v].push_back({u,a});
    }

    while(m--){
        cin >> u >> v;

        cout << bfs(u, v) << "\n";
    }

}

