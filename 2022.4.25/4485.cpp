//난이도 : 골드4, 유형 : 최단경로, bfs

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef tuple<int,int,int> tu;
typedef vector<p> vc;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int cnt = 1,n,dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};;

    while(1) {
        cin >> n;
        if(!n) return 0;
        int board[126][126],dist[126][126];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
                dist[i][j] = INF;
            }
        }

        auto solve = [&](int x,int y){
            queue<p> q;
            q.push({x,y});
            dist[x][y] = board[x][y];

            while(!q.empty()){
                auto cur = q.front();q.pop();

                for(int i=0;i<4;i++){
                    int nx = dx[i] + cur.F, ny = dy[i] + cur.S;

                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

                    if(dist[nx][ny] > dist[cur.F][cur.S] + board[nx][ny]){
                        dist[nx][ny] = dist[cur.F][cur.S] + board[nx][ny];
                        q.push({nx,ny});
                    }
                }
            }
            return dist[n-1][n-1];
        };

        cout << "Problem " << cnt++ << ": " << solve(0, 0) << "\n";
    }
}

