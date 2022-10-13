// 난이도 : 골드2, 유형 : 우선순위 큐, 위상정렬

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

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vc graph[32001];
    int n, m, a, b, degree[32001] = {0, };
    auto bfs = [&](){
        priority_queue<int, vc, greater<>> pq;

        for(int i=1;i<=n;i++)
            if(!degree[i]) pq.push(i);

        while(!pq.empty()){
            int cur = pq.top();pq.pop();
            cout << cur << ' ';

            for(auto next : graph[cur]){
                degree[next]--;

                if(!degree[next]) pq.push(next);
            }
        }
    };


    cin >> n >> m;

    while(m--){
        cin >> a >> b;

        graph[a].push_back(b);
        degree[b]++;
    }

    bfs();

}

