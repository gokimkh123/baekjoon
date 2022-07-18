// 난이도 : 골드 2, 유형 : 완전탐색, 시뮬레이션

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#define l long long
using namespace std;

int board[21][21],n,cy[21][21];

void rotation(){
    int temp[21][21];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            temp[i][j] = board[i][j];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            board[i][j] = temp[n-j-1][i];
    }
}

void solve(int dir){
    while(dir--) rotation();

    for(int i=0;i<n;i++){
        int temp[22] = {},cnt = 0;

        for(int j=0;j<n;j++){
            if(!board[i][j]) continue;

            if(!temp[cnt]) temp[cnt] = board[i][j];
            else if(temp[cnt] == board[i][j]) temp[cnt++] *= 2;
            else temp[++cnt] = board[i][j];
        }

        for(int j=0;j<n;j++)
            board[i][j] = temp[j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int ans = -1;
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            cy[i][j] = board[i][j];
        }
    }

    for(int x=0;x<(1 << 10);x++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                board[i][j] = cy[i][j];
        }

        int temp = x;

        for(int i=0;i<5;i++){
            int dir = temp % 4;
            temp /= 4;

            solve(dir);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                ans = max(ans,board[i][j]);
        }
    }

    cout << ans;
}
