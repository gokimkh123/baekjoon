//난이도 : 실버1, 유형 : 구현, 시뮬레이션

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

string Map[201];
int R,C,N,Time[201][201];
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

void print(){
    for(int i=0;i<R;i++)
        cout << Map[i] << '\n';
}

void Fill(int cnt){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++)
            if (Map[i][j] == '.') Map[i][j] = 'O',Time[i][j] = cnt + 3;
    }
}

void Boom(int cnt){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(Time[i][j] == cnt){
                Map[i][j] = '.';
                for(int k=0;k<4;k++) {
                    int nx = i + dx[k], ny = j + dy[k];

                    if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;

                    Map[nx][ny] = '.';
                }
                Time[i][j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


    cin >> R >> C >> N;

    for(int i=0;i<R;i++){
        cin >> Map[i];
        for(int j=0;j<C;j++)
            if(Map[i][j] == 'O') Time[i][j] = 3;
    }
    int cnt = 2;

    while(cnt <= N){
        if(cnt % 2 == 0) Fill(cnt);
        else if(cnt % 2 == 1) Boom(cnt);
        cnt++;
    }

    print();

}

