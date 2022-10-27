// 난이도 : 골드5, 유형 : 경로추적, bfs

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tu;
typedef vector<pa> vc;

int route[2001 * 2001];
char ans[2001][2001];

void print(int x, int m){
    if(x == 0) return;

    print(route[x], m);
    ans[x / m][x % m] = '.';
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
    bool vis[2001][2001] = {0, };
    char board[2001][2001];
    vc Start;

    auto bfs = [&](){
        int StartX = Start[0].first, StartY = Start[0].second;
        int EndX = Start[1].first, EndY = Start[1].second;
        queue<pa> q;
        q.push({StartX, StartY});
        vis[StartX][StartY] = true;

        while(!q.empty()){
            auto cur = q.front();q.pop();

            if(cur.first == EndX && cur.second == EndY)
                break;


            for(int i=0;i<4;i++){
                int nx = dx[i] + cur.first, ny = dy[i] + cur.second;

                if(nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] || board[nx][ny] == '+') continue;

                q.push({nx, ny});
                vis[nx][ny] = true;
                route[nx * m + ny] = cur.first * m + cur.second;

            }
        }
        print(EndX * m + EndY, m);
    };

    cin >> n >> m;

    for(int i=0;i<n;i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == '.') ans[i][j] = '@';
            else ans[i][j] = board[i][j];

            if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == '.') Start.push_back({i,j});
        }
    }


    bfs();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout << ans[i][j];
        cout << "\n";
    }

}
