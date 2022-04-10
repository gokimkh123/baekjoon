//난이도 : 골드5, 유형 : 구현, bfs

#include <bits/stdc++.h>
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef vector<p> vc;

int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};
int board[51][51],L,R,N;
bool check[51][51],on;

void bfs(int x,int y){
    vc v;
    queue<p> q;
    q.push({x,y}),check[x][y] = true,v.emplace_back(x,y);

    while(!q.empty()){
        p cur = q.front();q.pop();

        for(int i=0;i<4;i++){
            int nx = dx[i] + cur.F, ny = dy[i] + cur.S;

            if(nx < 0 || ny < 0 || nx >= N || ny >= N || check[nx][ny]) continue;
            int temp = abs(board[cur.F][cur.S] - board[nx][ny]);

            if(L <= temp && temp <= R){
                check[nx][ny] = true;
                v.emplace_back(nx,ny), q.push({nx,ny});
            }
        }
    }

    int cnt = 0,size = int(v.size());

    for(auto &i : v)
        cnt += board[i.F][i.S];

    if(size > 1){
        int temp = cnt / size;

        for(auto &i : v)
            board[i.F][i.S] = temp;

        on = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int ans = 0;
    cin >> N >> L >> R;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cin >> board[i][j];
    }

    while(1) {
        on = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!check[i][j]) bfs(i, j);
            }
        }
        if(!on){
            cout << ans;
            return 0;
        }

        memset(check,false,sizeof(check));
        ans++;

    }
}

