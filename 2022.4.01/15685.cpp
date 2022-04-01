//난이도 : 골드4, 유형 : 구현

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<int>
#define F first
#define S second
using namespace std;

bool board[101][101];
int st,en;
int dx[4] = {0,-1,0,1},dy[4] = {1,0,-1,0};

void solve(vc &dir){
    int size = int(dir.size());

    for(int i=size-1;i>=0;i--){
        int next = (dir[i] + 1) % 4;

        st += dx[next], en += dy[next];
        board[st][en] = true;
        dir.push_back(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, x, y, d, g, ans = 0;

    cin >> n;
    while(n--){
        cin >> y >> x >> d >> g;

        vc dir;

        st = x + dx[d], en = y + dy[d];
        board[st][en] = board[x][y] = true;

        dir.push_back(d);

        for(int i=0;i<g;i++)
            solve(dir);
    }

    for(int i=0;i<=99;i++){
        for(int j=0;j<=99;j++)
            if(board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1]) ans++;
    }

    cout << ans;
}
