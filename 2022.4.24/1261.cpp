//난이도 : 골드4, 유형 : bfs, 최단경로

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

int n,m,board[101][101],dx[] = {1,-1,0,0},dy[] = {0,0,1,-1},dist[101][101];
bool check[101][101];
string temp;

int bfs(int x,int y){

    dist[x][y] = 0;
    queue<p> q;
    q.push({x,y});

    while(!q.empty()){

        p cur = q.front();q.pop();

        for(int i=0;i<4;i++){
            int nx = dx[i] + cur.F, ny = dy[i] + cur.S;

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if(board[nx][ny] == 1){
                if(dist[nx][ny] > dist[cur.F][cur.S] + 1){
                    dist[nx][ny] = dist[cur.F][cur.S] + 1;
                    q.push({nx,ny});
                }

            }
            else if(board[nx][ny] == 0){
                if(dist[nx][ny] > dist[cur.F][cur.S]){
                    dist[nx][ny] = dist[cur.F][cur.S];
                    q.push({nx,ny});
                }
            }
        }
    }
    return dist[n-1][m-1];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> m >> n;

    for(int i=0;i<n;i++){
        cin >> temp;

        for(int j=0;j<m;j++){
            board[i][j] = temp[j] - '0';
            dist[i][j] = INF;
        }
    }

    cout << bfs(0,0);

}

