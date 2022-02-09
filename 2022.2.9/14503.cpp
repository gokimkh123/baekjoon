//난이도 : 골드5, 유형 : 완전탐색, 시뮬레이션

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <stack>
#define l long long
#define INF 2e9
using namespace std;

int n,m,board[51][51],ans;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


void dfs(int r,int c,int d){


    if(!board[r][c]) ans++;
    board[r][c] = -1;
    bool check = false;

    for(int i=0;i<4;i++){
        d = (d + 3) % 4;
        if(!board[r + dx[d]][c + dy[d]]){
            r += dx[d];c += dy[d];
            check = true;
            break;
        }
    }
    if(!check && board[r-dx[d]][c-dy[d]] == 1) return;
    else if(!check) r -= dx[d],c -= dy[d];

    dfs(r,c,d);

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int r,c,d;

    cin >> n >> m >> r >> c >> d;       // 0:북,1:동,2:남,3:서

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> board[i][j];
    }

    dfs(r,c,d);

   cout << ans;
}

/*
      0 -> 3 (d+3) % 4왼쪽 회전
      1 -> 0
      2 -> 1
      3 -> 2
*/
