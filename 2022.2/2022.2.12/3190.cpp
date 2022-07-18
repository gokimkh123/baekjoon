//난이도 : 골드5, 유형: 시뮬레이션

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <deque>
#define l long long
#define INF 2e9
using namespace std;

int n,board[101][101],vis[101][101],k,L;
char save[10001];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int bfs(){
    int d = 1,time = 0;
    deque<pair<int,int>> q;
    q.push_front({0,0});

    while(1){
        pair<int,int> cur = q.front();
        int x = cur.first,y = cur.second;

        board[x][y] = 1;
        time++;

        int nx = x + dx[d],ny = y+ dy[d];

        if(nx < 0 | ny < 0 || nx >= n || ny >= n) return time;
        if(board[nx][ny] == 1) return time;

       if(board[nx][ny] != -1){
           pair<int,int> tail = q.back();
           board[tail.first][tail.second] = 0;
           q.pop_back();
       }

        if(save[time] == 'D') d = (d+1) % 4;
        else if(save[time] == 'L') d = (d+3) % 4;

        q.push_front({nx,ny});
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> k;

    for(int i=0;i<k;i++) {int a,b;cin >> a >> b;board[a-1][b-1] = -1;}

    cin >> L;

    for(int i=0;i<L;i++){
        int a;char b; cin >> a >> b;save[a] = b;
    }

    cout << bfs();

}
/*
  0:북,1:동,2:남,3:서

  L일때 (d+3) % 4
  D일때 (d+1) % 4
 */
