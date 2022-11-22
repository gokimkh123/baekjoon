// 난이도 : 골드5, 유형 : 다익스트라

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

    int n, m, a, b, c, dist[50001];
    vc v[50001];
    auto dj = [&](int st = 1){
        priority_queue<pa, vc, greater<>> q;
        dist[st] = 0;
        q.push({0, st});

        while(!q.empty()){
            int cost = q.top().first, Cur = q.top().second;q.pop();

            if(dist[Cur] != cost) continue;

            for(auto next : v[Cur]){
                if(dist[next.second] <= dist[Cur] + next.first) continue;

                dist[next.second] = dist[Cur] + next.first;
                q.push({dist[next.second], next.second});
            }
        }

        return dist[n];
    };


    cin >> n >> m;

    while(m--){
        cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }

    fill(dist, dist + n + 1, INF);

    cout << dj();

}
