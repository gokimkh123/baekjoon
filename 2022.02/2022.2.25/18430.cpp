//난이도 : 골드5, 유형 : 백트래킹

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

int n,m,arr[6][6],MAX,ans;
bool check[6][6];

int a(int x,int y){
    return arr[x][y] + arr[x][y+1] * 2 + arr[x+1][y+1];
}

int b(int x,int y){
    return arr[x][y] + arr[x][y+1] * 2 + arr[x-1][y+1];
}

int c(int x,int y){
    return arr[x][y] + arr[x+1][y] * 2 + arr[x+1][y+1];
}

int d(int x,int y){
    return arr[x][y] * 2 + arr[x+1][y] + arr[x][y+1];
}

void back(int x,int y,int sum){
    if(y == m){
        y = 0;
        x++;
    }
    if(x == n){
        ans = max(ans,sum);
        return;
    }

    if(!check[x][y]){
        if(y + 1 < m && x + 1 < n && !check[x][y+1] && !check[x+1][y+1]){
            check[x][y] = check[x][y+1] = check[x+1][y+1] = true;
            back(x,y+1,sum + a(x,y));
            check[x][y] = check[x][y+1] = check[x+1][y+1] = false;
        }

        if(x - 1 >= 0 && y + 1 < m && !check[x-1][y+1] && !check[x][y+1]){
            check[x][y] = check[x][y+1] = check[x-1][y+1] = true;
            back(x,y+1,sum + b(x,y));
            check[x][y] = check[x][y+1] = check[x-1][y+1] = false;
        }
        if(x + 1 < n && y + 1 < m && !check[x+1][y] && !check[x+1][y+1]){
            check[x][y] = check[x+1][y] = check[x+1][y+1] = true;
            back(x,y+1,sum + c(x,y));
            check[x][y] = check[x+1][y] = check[x+1][y+1] = false;
        }
        if(x + 1 < n && y +1 < m && !check[x+1][y] && !check[x][y+1]){
            check[x][y] = check[x+1][y] = check[x][y+1] = true;
            back(x,y+1,sum + d(x,y));
            check[x][y] = check[x+1][y] = check[x][y+1] = false;
        }
    }


    back(x,y+1,sum);
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> arr[i][j];
    }

    back(0,0,0);

    cout << ans;
}

