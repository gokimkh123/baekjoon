//난이도 : 골드5, 유형 : dfs,완전탐색,시뮬레이션

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

int board[501][501],n,m,ans = -1;
bool check[501][501];

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

void dfs(int x,int y,int sum,int len){
    if(len == 4){
        ans = max(ans,sum);
        return;
    }

    for(int i=0;i<4;i++){
        int nx = x + dx[i],ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny]) continue;

        check[nx][ny] = true;
        dfs(nx,ny,sum + board[nx][ny],len + 1);
        check[nx][ny] = false;
    }

}

void ex(int x,int y){
    if(y+2 < m){
        int temp = 0;

        for(int i=0;i<3;i++)    temp += board[x][y+i];

        if(x-1 >= 0) ans = max(ans,temp + board[x-1][y+1]);
        if(x+1 < n) ans = max(ans,temp + board[x+1][y+1]);
    }

    if(x+2 < n){
        int temp = 0;

        for(int i=0;i<3;i++) temp += board[x+i][y];

        if(y+1 < m) ans = max(ans,temp + board[x+1][y+1]);
        if(y-1 >= 0) ans = max(ans,temp + board[x+1][y-1]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)    cin >> board[i][j];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            check[i][j] = true;
            dfs(i,j,board[i][j],1);
            check[i][j] = false;

            ex(i,j);
        }
    }

    cout << ans;

}

