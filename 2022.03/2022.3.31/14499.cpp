//난이도 : 골드4, 유형 : 구현

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<int>
#define F first
#define S second
using namespace std;

int dice[4][3],board[21][21],x,y,n,m;

bool UpDownMove(int move){
    int UD = 1;
    if(move == 3) UD *= -1;

    if(x + UD < 0 || x + UD >= n) return false;
    x += UD;

    int temp = dice[3][1];

    if(UD < 0){
        dice[3][1] = dice[0][1];
        dice[0][1] = dice[1][1];
        dice[1][1] = dice[2][1];
        dice[2][1] = temp;
    }
    else{
        dice[3][1] = dice[2][1];
        dice[2][1] = dice[1][1];
        dice[1][1] = dice[0][1];
        dice[0][1] = temp;
    }
    if(board[x][y] != 0){
        dice[3][1] = board[x][y];
        board[x][y] = 0;
    }
    else if(board[x][y] == 0) board[x][y] = dice[3][1];

    return true;
}

bool LeftRightMove(int move){
    int LR = 1;
    if(move == 2) LR *= -1;

    if(y + LR < 0 || y + LR >= m) return false;
    y += LR;

    int temp = dice[3][1];

    if(LR < 0){
        dice[3][1] = dice[1][0];
        dice[1][0] = dice[1][1];
        dice[1][1] = dice[1][2];
        dice[1][2] = temp;
    }
    else{
        dice[3][1] = dice[1][2];
        dice[1][2] = dice[1][1];
        dice[1][1] = dice[1][0];
        dice[1][0] = temp;
    }

    if(board[x][y] != 0){
        dice[3][1] = board[x][y];
        board[x][y] = 0;
    }
    else if(board[x][y] == 0) board[x][y] = dice[3][1];

    return true;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    int k,move;

    cin >> n >> m >> x >> y >> k;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> board[i][j];
    }

    for(int i=0;i<k;i++){
        bool check = true;
        cin >> move;

        if(move == 3 || move == 4) check = UpDownMove(move);
        else check = LeftRightMove(move);
        if(check) cout << dice[1][1] << "\n";
    }
}

