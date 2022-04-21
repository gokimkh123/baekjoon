//난이도 : 플레5, 유형 : bfs

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

int R,C,dx[] = {1,-1,0,0},dy[] = {0,0,1,-1},SwanX,SwanY;
bool check[1501][1501];
char board[1501][1501];
queue<p> save;

bool Bfs(){
    queue<p> q;
    if(save.empty()){
        check[SwanX][SwanY] = true;
        q.push({SwanX,SwanY});
    }
    else q = save,save = queue<p>();

    while(!q.empty()){
        p cur = q.front();q.pop();

        for(int i=0;i<4;i++){
            int nx = cur.F + dx[i], ny = cur.S + dy[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C || check[nx][ny]) continue;

            if(board[nx][ny] == 'L') return true;

            if(board[nx][ny] == 'X') save.push({nx,ny});
            else q.push({nx,ny});
            check[nx][ny] = true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    queue<p> v;
    bool on = false;
    int ans = 0;
    cin >> R >> C;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> board[i][j];

            if(board[i][j] == 'L' && !on)  SwanX = i, SwanY = j,on = true;
            if(board[i][j] == '.' || board[i][j] == 'L') v.push({i,j});
        }
    }

    auto Melt = [&](){
        int size = int(v.size());

        while(size--){
            p cur = v.front();v.pop();

            for(int i=0;i<4;i++){
                int nx = cur.F + dx[i], ny = cur.S + dy[i];

                if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;

                if(board[nx][ny] == 'X') board[nx][ny] = '.',v.push({nx,ny});
            }
        }
    };

    while(1){
        if(Bfs()){
            cout << ans;
            break;
        }
        Melt();
        ans++;
    }
}
