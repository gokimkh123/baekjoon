// 난이도 : 골드 3, 유형 : 다익스트라, 최단경로, 경로추적

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#define l long long
#define INF 1e9
using namespace std;

int V, E, s, from, to, val, End;
priority_queue<pair<int, int> > qu;
int dist[100001],route[100001];
vector<pair<int, int> > arr[1001];
vector<int> v;

void dijkstra(int start){
    qu.push({start, 0});
    dist[start] = 0;

    while (!qu.empty()) {
        int here = qu.top().first;
        int cost = -qu.top().second;

        qu.pop();

        if(dist[here] < cost) continue;

        for (int i = 0; i < arr[here].size(); i++) {
            int next = arr[here][i].first;
            int nextCost = arr[here][i].second;

            if (dist[next] > cost + nextCost) {
               // cout << here << " " << next << "\n";
                route[next] = here;
                dist[next] = cost + nextCost;
                qu.push({next, -dist[next]});
            }
        }
    }
    int temp = End;
    while(temp){
        v.push_back(temp);
        temp = route[temp];
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> V >> E ;

    for (int i = 0; i < E; i++) {
        cin >> from >> to >> val;

        arr[from].push_back({to, val});
    }
    fill(dist, dist + V + 1, INF);
    cin >> s >> End;

    dijkstra(s);

    cout << dist[End] << "\n" << v.size() << "\n";

    for(int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << " ";
}
