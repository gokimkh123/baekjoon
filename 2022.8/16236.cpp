// 난이도 : 골드3, 유형 : bfs

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


int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int board[21][21], check[21][21];
    int n, shark_X, shark_Y, Min_X, Min_Y, Min_dist, Size = 2, eat = 0, ans = 0;
    int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

    auto Init = [&](){
        Min_X = 21 * 21 + 1, Min_Y = 21 * 21 + 1, Min_dist = 21 * 21 + 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                check[i][j] = -1;
        }
    };

    auto BFS = [&](){
        queue<p> q;
        q.push({shark_X,shark_Y});
        check[shark_X][shark_Y] = 0;

        while(!q.empty()){
            auto cur = q.front();q.pop();

            for(int i=0;i<4;i++){
                int nx = cur.F + dx[i], ny = cur.S + dy[i];

                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(check[nx][ny] != -1 || board[nx][ny] > Size) continue;

                check[nx][ny] = check[cur.F][cur.S] + 1;

                if(board[nx][ny] != 0 && board[nx][ny] < Size){
                    if(Min_dist > check[nx][ny]){
                        Min_dist = check[nx][ny];
                        Min_X = nx, Min_Y = ny;
                    }
                    else if(Min_dist == check[nx][ny]){
                        if(Min_X > nx)  Min_X = nx, Min_Y = ny;

                        else if(Min_X == nx){
                            if(Min_Y > ny) Min_X = nx, Min_Y = ny;
                        }

                    }
                }
                q.push({nx,ny});
            }
        }
    };

    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            if(board[i][j] == 9) shark_X = i, shark_Y = j, board[i][j] = 0;
        }
    }


    while(1){
        Init();
        BFS();
        if(Min_X != 21 * 21 + 1 && Min_Y != 21 * 21 + 1){
            shark_X = Min_X, shark_Y = Min_Y;
            ans += check[shark_X][shark_Y];
            eat++;

            if(eat == Size) Size++, eat = 0;

            board[shark_X][shark_Y] = 0;
        }
        else break;
    }


    cout << ans;



}

