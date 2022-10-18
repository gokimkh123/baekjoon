// 난이도 : 골드 2, 유형 : 위상정렬

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int,int> tu;
typedef vector<pa> vc;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m, x, y, k, degree[101] = { 0, }, temp[101] = {0, };
    vc graph[101];


    auto solved = [&](){
        queue<int> q;
        vector<int> ans;

        q.push(n);
        temp[n] = 1;

        while(!q.empty()){
            auto cur= q.front();q.pop();

            if(graph[cur].empty()) ans.push_back(cur);

            for(auto next : graph[cur]){
                degree[next.first]--;
                temp[next.first] += next.second * temp[cur];
                if(!degree[next.first]) q.push(next.first);
            }
        }


        sort(all(ans));

        for(auto &i : ans)
            cout << i << " " << temp[i] << "\n";

    };

    cin >> n >> m;

    while(m--){
        cin >> x >> y >> k;
        graph[x].push_back({y,k});
        degree[y]++;
    }

    solved();

}
