//난이도 : 골드5, 유형 : bfs

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef tuple<int,int,int> tu;
typedef vector<tu> vc;

int board[3001][3001],dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
bool check[3001][3001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n,m,startX,startY,MIN = 9 * 1000000 + 1;
    string s;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<m;j++){
            board[i][j] = s[j] - '0';
            if(board[i][j] == 2) startX = i, startY = j;
        }
    }


    auto print = [=](){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout << board[i][j] << " ";
            cout << "\n";
        }
    };


    auto bfs = [&]() -> void{
        int cnt,x,y;
        queue<tu> q;
        check[startX][startY] = true;
        board[startX][startY] = 0;
        q.push({startX,startY,0});

        while(!q.empty()){
            tie(x,y,cnt) = q.front();q.pop();

            if(board[x][y]) MIN = min(MIN,cnt);

            for(int i=0;i<4;i++){
                int nx = x + dx[i], ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(check[nx][ny] || board[nx][ny] == 1) continue;

                check[nx][ny] = true;
                q.push({nx,ny,cnt+1});
            }
        }
    };

    bfs();

    if(MIN == 9 * 1000000 + 1) cout << "NIE";
    else cout << "TAK\n" << MIN;
}


