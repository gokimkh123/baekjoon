// 난이도 : 골드3, 유형 : dp, 위상정렬

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int,int> tu;
typedef vector<int> vc;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, k, t, u, v, end;
    int degree[1001] = {0, }, w[1001] = {0, }, dp[1001] = {0, };
    vc graph[10001];

    auto solved = [&](){
        int ans = INF;
        queue<int> q;

        for(int i=1;i<=n;i++)
            if(!degree[i]) q.push(i), dp[i] = w[i];

        while(!q.empty()){
            int cur = q.front();q.pop();

            if(cur == end){
                ans = min(ans, dp[cur]);
                continue;
            }

            for(int next : graph[cur]) {
                degree[next]--;
                if (!degree[next]) q.push(next);

                dp[next] = max(dp[next], dp[cur] + w[next]);
            }
        }

        return ans;

    };

    cin >> t;

    while(t--){
        cin >> n >> k;
        for(int i=1;i<=n;i++)
            cin >> w[i];
        while(k--){
            cin >> u >> v;
            degree[v]++;
            graph[u].push_back(v);
        }

        cin >> end;

        cout << solved() << "\n";

        for(int i=1;i<=n;i++)
            graph[i].clear(), dp[i] = w[i] = degree[i] = 0;
    }

}
