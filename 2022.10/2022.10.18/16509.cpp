// 난이도 : 골드 5, 유형 : bfs, 구현

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tu;
typedef vector<pa> vc;

int dx[8][3] = { {-1, -2, -3}, {-1, -2, -3}, {0, -1, -2}, {0, 1, 2}, {1, 2, 3}, {1, 2, 3}, {0, -1, -2}, {0, 1, 2} };
int dy[8][3] = { {0, -1, -2}, {0, 1, 2}, {-1, -2, -3}, {-1, -2, -3}, {0, -1, -2}, {0, 1, 2}, {1, 2, 3}, {1, 2, 3} };
bool vis[10][9];
int r1, c1, r2, c2;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    auto bfs = [&](){
        int x, y, cnt;
        queue<tu> q;
        vis[r1][c1] = true;

        q.push({r1, c1, 1});

        while(!q.empty()){
            tie(x, y, cnt) = q.front();q.pop();

            for(int i=0;i<8;i++){
                for(int j=0;j<3;j++){
                    int nx = x + dx[i][j], ny = y + dy[i][j];

                    if(nx < 0 || nx > 9 || ny < 0 || ny > 8 || vis[nx][ny]) continue;

                    if(nx == r2 && ny == c2){  // 왕을 지나간다면
                        if(j == 2) return cnt;
                        else break;
                    }

                    if(j == 2){     // 왕 없으면
                        vis[nx][ny] = true;
                        q.push({nx, ny, cnt + 1});
                    }
                }
            }
        }
        return -1;
    };

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    cout << bfs();

}
