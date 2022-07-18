// 난이도 : 골드 5, 유형 : 다익스트라, 최단경로

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
int dist[200001];
vector<pair<int, int> > arr[200001];

void dijkstra(int start){
    qu.push(make_pair(0, start));
    dist[start] = 0;

    while (!qu.empty()) {
        int cost = -qu.top().first;
        int here = qu.top().second;

        qu.pop();

        if(dist[here] < cost) continue;

        for (int i = 0; i < arr[here].size(); i++) {
            int next = arr[here][i].first;
            int nextCost = arr[here][i].second;

            if (dist[next] > cost + nextCost) {
                dist[next] = cost + nextCost;
                qu.push(make_pair(-dist[next], next));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> V >> E ;

    for (int i = 0; i < E; i++) {
        cin >> from >> to >> val;

        arr[from].push_back(make_pair(to, val));
    }
    fill(dist, dist + V + 1, INF);
    cin >> s >> End;

    dijkstra(s);

    cout << dist[End];
}
