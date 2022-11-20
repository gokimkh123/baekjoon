// 난이도 : 골드4, 유형 : 다익스트라

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int, int> tu;
typedef vector<pa> vc;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, e, a, b, c, dist[802], v1, v2;
    vc v[802];
    auto dj = [&](int st = 1){
        fill(dist, dist + n + 1, INF);
        priority_queue<pa, vc, greater<>> pq;
        dist[st] = 0;
        pq.push({dist[st], st});

        while(!pq.empty()){
            auto cur = pq.top();pq.pop();

            if(dist[cur.second] != cur.first) continue;

            for(auto next: v[cur.second]){
                if(dist[next.second] <= dist[cur.second] + next.first) continue;

                dist[next.second] = dist[cur.second] + next.first;

                pq.push({dist[next.second], next.second});
            }

        }
    };

    cin >> n >> e;

    for(int i=0;i<e;i++){
        cin >> a >> b >> c;

        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }

    cin >> v1 >> v2;

    dj(1);
    int St1V1 = dist[v1];
    int St1V2 = dist[v2];

    dj(v1);
    int Stv1v2 = dist[v2];
    int Stv1n = dist[n];

    dj(v2);
    int Stv2n = dist[n];

    int ans = INF;

    ans = min(ans, St1V1 + Stv1v2 + Stv2n);
    ans = min(ans, St1V2 + Stv1v2 + Stv1n);

    if(Stv1v2 >= INF || ans >= INF) cout << "-1";
    else cout << ans;


}
