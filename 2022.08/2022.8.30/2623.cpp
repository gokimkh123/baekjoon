// 난이도 : 골드 3, 유형 : 위상정렬

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

    vc graph[1001];
    int singer, m, degree[1001], u, v, n;

    auto bfs = [&](){
        vc result;
        queue<int> q;

        for(int i=1;i<=singer;i++)
            if(!degree[i]) q.push(i);

        while(!q.empty()){
            int cur = q.front();q.pop();
            result.push_back(cur);

            for(auto next : graph[cur]){
                degree[next]--;
                if(!degree[next]) q.push(next);
            }
        }

        return result;
    };

    cin >> singer >> m;

    while(m--){
        cin >> n >> u;

        for(int i=0;i<n-1;i++){
            cin >> v;
            graph[u].push_back(v);
            degree[v]++;
            u = v;
        }
    }

    vc ans = bfs();

    if(ans.size() != singer) cout << "0";
    else{
        for(auto &i : ans)
            cout << i << "\n";
    }
}

