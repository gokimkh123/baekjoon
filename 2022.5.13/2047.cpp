//난이도 : 미정(골드4 예정), 유형 : bfs

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

int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n,h,w;
    cin >> n;

    while(n--){
        int x,y;
        char board[97][97];
        cin >> h >> w;

        auto bfs = [&]() -> double{
            int cnt = 0;
            bool check[97][97];
            memset(check,false,sizeof(check));
            queue<p> q;

            q.push({x,y}), check[x][y] = true;

            while(!q.empty()){
                auto cur = q.front();q.pop();

                for(int i=0;i<4;i++){
                    int nx = dx[i] + cur.F, ny = dy[i] + cur.S;

                    if(nx < 0 || ny < 0 || nx >= h || ny >= w || board[nx][ny] == '#' || check[nx][ny]) continue;

                    cnt++;
                    q.push({nx,ny});
                    check[nx][ny] = true;
                }
            }

            return double(cnt);
        };

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> board[i][j];
                if(board[i][j] == 's') x = i,y = j;
            }
        }

        double ans = bfs();

        printf("%.2lf\n",ans);
    }
}

