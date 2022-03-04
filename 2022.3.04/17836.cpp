//난이도 : 골드5, 유형 : bfs


#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

int n,m,t,board[101][101],MIN = 100001;
bool check[101][101][2];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void bfs(int y,int x){
    queue<tuple<int,int,int,int>> q;
    q.push({y,x,0,0});
    check[y][x][0] = true;

    while(!q.empty()){
        int cx,cy,get,cnt;
        tie(cx,cy,get,cnt) = q.front();q.pop();

        if(board[cx][cy] == 2) get = 1;

        if(cx == n && cy == m)  MIN = min(MIN,cnt);

        for(int i=0;i<4;i++){
            int nx = cx + dx[i], ny = cy + dy[i];

            if(nx <= 0 || ny <= 0 || nx > n || ny > m) continue;

            if(get == 1){
                if(!check[nx][ny][get]){
                    check[nx][ny][get] = true;
                    q.push({nx,ny,get,cnt+1});
                }
            }
            else{
                if(!check[nx][ny][get] && board[nx][ny] != 1){
                    check[nx][ny][get] = true;
                    q.push({nx,ny,get,cnt+1});
                }
            }


        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m >> t;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cin >> board[i][j];
    }
    bfs(1,1);

    if(MIN == 100001 || MIN > t) cout << "Fail";
    else cout << MIN;
}
