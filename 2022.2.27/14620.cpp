//난이도 : 실버2, 유형 : 백트래킹, 완전탐색

#include <iostream>
#include <vector>
#include <cmath>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <deque>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define mod
using namespace std;

int map[11][11],n,ans = 20000;
bool check[11][11];


int solve(int y,int x){
    return map[y][x] + map[y+1][x] + map[y-1][x] + map[y][x+1] + map[y][x-1];
}

void back(int y,int x,int sum,int cnt){
    if(x == n)  x = 0,y++;
    if(cnt == 3) {ans = min(ans,sum);return;}
    if(y == n) return;

    if(!check[y][x]){
        if(x + 1 < n  && x - 1 >= 0 && y + 1 < n && y - 1 >= 0){
            if(!check[y+1][x] && !check[y-1][x] && !check[y][x+1] && !check[y][x-1]){

                check[y][x] = check[y+1][x] = check[y-1][x] = check[y][x+1] = check[y][x-1] = true;

                back(y,x+1,sum + solve(y,x),cnt + 1);

                check[y][x] = check[y+1][x] = check[y-1][x] = check[y][x+1] = check[y][x-1] = false;
            }
        }
    }

    back(y,x+1,sum,cnt);
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin >> map[i][j];
    }

    back(0,0,0,0);

    cout << ans;
}
