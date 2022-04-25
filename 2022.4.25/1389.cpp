//난이도 : 실버1, 유형 : 플로이드와샬

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef tuple<int,int,int> tu;
typedef vector<int> vc;

int n,dist[101][101];

void solve(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i == j) continue;

                if(dist[i][k] && dist[k][j]){
                    if (dist[i][j] == 0) dist[i][j] = dist[i][k] + dist[k][j];
                    else dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int m,a,b;

    cin >> n >> m;

    while(m--){
        cin >> a >> b;

        dist[a][b] = dist[b][a] = 1;
    }

    solve();

    int ans,temp = INF;

    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=1;j<=n;j++)
            cnt += dist[i][j];

        if(cnt < temp){
            temp = cnt;
            ans = i;
        }
    }

    cout << ans;
}

