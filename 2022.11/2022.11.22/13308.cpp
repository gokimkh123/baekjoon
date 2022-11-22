// 난이도 : 플레5, 유형 : 다익스트라, dp

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 1e15
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<ll,int, int> tu;
typedef vector<pa> vc;

int n, m, a, b, c, cost[2501];
ll dp[2501][2501];
vc v[2501];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    auto dj = [&](int st = 1){
        for(int i=1;i<=n;i++)
            for(int j=0;j<=2500;j++)
                dp[i][j] = INF;

        priority_queue<tu, vector<tu>, greater<>> q;
        q.push({0, st, cost[st]});

        while(!q.empty()){
            int c, oil;
            ll w;
            tie(w, c, oil) = q.top();q.pop();

            if(dp[c][oil] < w) continue;
            if(c == n) return w;

            for(auto next : v[c]){
                ll NextCost = w + next.first * oil;
                int NextPrice = min(oil, cost[next.second]);

                if(dp[next.second][oil] > NextCost){
                    dp[next.second][oil] = NextCost;
                    q.push({NextCost, next.second, NextPrice});
                }
            }
        }
    };


    cin >> n >> m;

    for(int i=1;i<=n;i++)
        cin >> cost[i];

    while(m--){
        cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }

    cout << dj();

}
