// 난이도 : 골드5, 유형 : bfs

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tu;
typedef vector<pa> vc;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m, board[51][51] = {0, }, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    int ans = 0,LenAns = 0;
    
    auto bfs = [&](int x, int y) -> pa{
        int vis[51][51] = {0, }, sum = 0, MaxLen = -1;

        queue<pa> q;
        q.push({x, y});
        vis[x][y] = 1;

        while(!q.empty()){
            auto cur = q.front();q.pop();

            for(int i=0;i<4;i++){
                int nx = dx[i] + cur.first, ny = dy[i] + cur.second;

                if(nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] || !board[nx][ny]) continue;

                q.push({nx, ny});
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(MaxLen < vis[i][j])
                    sum = board[x][y] + board[i][j], MaxLen = vis[i][j];
                else if(MaxLen == vis[i][j])
                    sum = max(sum, board[x][y] + board[i][j]);
            }
        }
        return {MaxLen, sum};
    };

    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> board[i][j];
    }

    for(int i=0;i<n;i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 0) {
                auto temp = bfs(i, j);

                if(temp.first > LenAns)
                    LenAns = temp.first, ans = temp.second;

                else if(temp.first == LenAns)
                    ans = max(ans, temp.second);
            }
        }
    }

    cout << ans;
}
