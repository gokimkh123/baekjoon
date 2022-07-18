// 난이도 : 골드 3, 유형: bfs, 백트래킹(재귀함수로 구현 가능, 하지만 나는 next_permutation사용)

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

string board[6];
int arr[27];
int dx[4] = {0,0,1,-1},ans;
int dy[4] = {1,-1,0,0};
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int cnt = 0;

    for(int i=0;i<5;i++){
        cin >> board[i];
        for(auto &j : board[i]){
            if(j == 'Y') arr[cnt++] = 2;
            else arr[cnt++] = 1;
        }
    }



    for(int i=0;i<25;i++)
        v.push_back(i < 7 ? 0 : 1);

    do{
        bool check[6][6] = { },vis[6][6] = { };
        int da = 0, im = 0;
        queue<tuple<int,int>> q;
        for(int i=0;i<25;i++){
            if(!v[i]){
                int x = i / 5, y = i % 5;
                check[x][y] = true;
                if(q.empty()){
                    q.push({x,y});
                    vis[x][y] = true;
                }
            }
        }

        while(!q.empty()){
            int cx,cy;
            tie(cx,cy) = q.front();q.pop();

            if(board[cx][cy] == 'S') da++;
            else im++;

            for(int i=0;i<4;i++){
                int nx = cx + dx[i], ny = cy + dy[i];

                if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || !check[nx][ny] || vis[nx][ny]) continue;
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }
        if(da + im >= 7 && da >= 4) ans++;
    }while(next_permutation(v.begin(),v.end()));

    cout << ans;
}
