// 난이도 : 골드5, 유형 : 위상정렬, dp

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

    vc graph[10001];
    int n, degree[10001] = {0, }, w[10001] = {0, }, k, a, dp[10001];

    auto solved = [&](){
        int ans = 0;
        queue<int> q;

        for(int i=1;i<=n;i++)
            if(!degree[i]) q.push(i), dp[i] = w[i];

        while(!q.empty()){
            int cur = q.front();q.pop();

            for(int next : graph[cur]){
                degree[next]--;
                if(!degree[next]) q.push(next);

                dp[next] = max(dp[next], dp[cur] + w[next]);
            }

            ans = max(ans, dp[cur]);
        }

        return ans;

    };

    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> w[i] >> k;

        while(k--){
            cin >> a;
            degree[i]++;
            graph[a].push_back(i);
        }
    }

    cout << solved();
}
