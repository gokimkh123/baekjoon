// 난이도 : 골드 5, 유형 : 완전탐색, bfs, 시뮬레이션

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int arr[9][9],n,m,cy[9][9];
vector<tuple<int,int> > cctv;
int nx[4] = {1,0,-1,0};
int ny[4] = {0,1,0,-1};     //


void bfs(int x,int y,int dir){
    dir %= 4;

    while(1){
        x += nx[dir],y += ny[dir];

        if(x < 0 || y < 0 || x >= n || y >= m || arr[x][y] == 6) return;

        if(arr[x][y] != 0) continue;

        arr[x][y] = -1;
    }

}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;

    int ans = n * m + 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            cy[i][j] = arr[i][j];
            if(arr[i][j] != 0 && arr[i][j] != 6) cctv.push_back({i,j});

        }
    }

    for(int i=0;i<(1<<(cctv.size() * 2));i++){
        int re = i;

        for(int x=0;x<n;x++){
            for(int y=0;y<m;y++)
                arr[x][y] = cy[x][y];
        }

        for(int k=0;k<cctv.size();k++){
            int dir = re % 4;
            re /= 4;
            int x,y;
            tie(x,y) = cctv[k];

            if(arr[x][y] == 1)  bfs(x,y,dir);
            else if(arr[x][y] == 2){bfs(x,y,dir),bfs(x,y,dir+2);}
            else if(arr[x][y] == 3){bfs(x,y,dir);bfs(x,y,dir+1);}
            else if(arr[x][y] == 4){bfs(x,y,dir);bfs(x,y,dir+1),bfs(x,y,dir+2);}
            else if(arr[x][y] == 5){bfs(x,y,dir);bfs(x,y,dir+2),bfs(x,y,dir+1);bfs(x,y,dir+3);}
        }

        int cnt = 0;

        for(int x=0;x<n;x++){
            for(int y=0;y<m;y++){
                if(arr[x][y] == 0) cnt++;
            }
        }
        ans = min(ans,cnt);
    }
    cout << ans;
}
