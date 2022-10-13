//난이도 : 골드4, 유형 : 구현, 시뮬레이션

#include <bits/stdc++.h>
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef vector<p> vc;

int board[51][51],temp[51][51],R,C,T;
int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};
vc AirClear;

void DiffUse(int x,int y){
    int cnt = 0;
    temp[x][y] += board[x][y];

    for(int i=0;i<4;i++){
        int nx = dx[i] + x, ny = dy[i] + y;
        if(nx < 0 || ny < 0 || nx >= R || ny >= C || board[nx][ny] == -1) continue;
        cnt++, temp[nx][ny] += board[x][y] / 5;
    }
    temp[x][y] -= (board[x][y] / 5) * cnt;
}

void Clear(int x,int y,int dir){
    for(int i=C-1;i>y;i--)
        temp[x][i] = board[x][i-1];
    temp[x][y+1] = 0;

    if(dir == 1){
        for(int i=0;i<=x-1;i++)
            temp[i][C-1] = board[i+1][C-1];

        for(int i=0;i<C-1;i++)
            temp[0][i] = board[0][i+1];

        for(int i=x-1;i>=1;i--)
            temp[i][0] = board[i-1][0];
        if(y != 0) temp[x][0] = board[x-1][0];

    }
    else{
        for(int i=R-1;i>x;i--)
            temp[i][C-1] = board[i-1][C-1];

        for(int i=0;i<C-1;i++)
            temp[R-1][i] = board[R-1][i+1];

        for(int i=x+1;i<R-1;i++)
            temp[i][0] = board[i+1][0];

        if(y != 0) temp[x][0] = board[x+1][0];
    }

    for(int i=y-1;i>=1;i--)
        temp[x][i] = board[x][i-1];
    temp[x][1] = board[x][0];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int ans = 0;
    cin >> R >> C >> T;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> board[i][j];
            if(board[i][j] == -1) AirClear.emplace_back(i,j);
        }
    }

    auto cp = [&](){
        for(int i=0;i<R;i++) {
            for (int j = 0; j < C; j++) {
                if(board[i][j] == -1) continue;
                temp[i][j] <= 0 ? board[i][j] = 0 : board[i][j] = temp[i][j];
            }
        }
    };

    while(T--){
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++)
                if(board[i][j] != -1 && board[i][j] != 0) DiffUse(i,j);
        }
        cp();
        Clear(AirClear[0].F,AirClear[0].S,1);
        Clear(AirClear[1].F,AirClear[1].S,-1);
        cp();

        memset(temp,0,sizeof(temp));
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++)
            if(board[i][j] != -1) ans += board[i][j];
    }

    cout << ans;
}

