//난이도 : 골드4, 유형 : bfs, 구현, 시뮬레이션

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<p>
#define F first
#define S second
using namespace std;

int dx[] = {0,0,1,-1},dy[] = {1,-1,0,0},ans;
string board[13];
bool on = true;

void Down(){
    for(int j=0;j<6;j++){
        for(int i=12;i>=0;i--){
            if(board[i][j] != '.'){
                for(int k=11;k>i;k--){
                    if(board[k][j] == '.'){
                        board[k][j] = board[i][j];
                        board[i][j] = '.';
                        break;
                    }
                }
            }
        }
    }
}

void bfs(int y,int x){
    bool check[13][7];
    vc save;
    memset(check,false,sizeof(check));
    queue<p> q;
    q.push({y,x});

    while(!q.empty()){
        p cur = q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx = dx[i] + cur.F, ny = dy[i] + cur.S;

            if(nx < 0 || ny < 0 || nx >= 12 || ny >= 6 || board[y][x] != board[nx][ny] || check[nx][ny]) continue;

            check[nx][ny] = true;
            save.emplace_back(nx,ny);
            q.push({nx,ny});
        }
    }

    if(save.size() >= 4){
        for(auto &i : save) board[i.F][i.S] = '.';
        on = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    for(int i=0;i<12;i++)
        cin >> board[i];

    while(true){
        if(!on){
            cout << ans;
            return 0;
        }

        on = false;

        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                if(board[i][j] != '.') bfs(i,j);
            }
        }

        if(on){
            ans++;
            Down();
        }
    }
}

