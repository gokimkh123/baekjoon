//난이도 : 골드5, 유형 : 우선순위 큐, bfs

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef tuple<int,int,int> tu;
typedef vector<tu> vc;

int board[201][201],dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    priority_queue<tu,vc,greater<>> temp;

    int n,k,s,x,y;

    cin >> n >> k;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            if(board[i][j]) temp.push({board[i][j],i,j});
        }

    }

    cin >> s >> x >> y;

    auto bfs = [&]()-> void{
        priority_queue<tu,vc,greater<>> a;
        int num,curX,curY;
        bool check[201][201];
        memset(check,false,sizeof(check));

        while(!temp.empty()){
            tie(num,curX,curY) = temp.top();temp.pop();
            for(int j=0;j<4;j++){
                int nx = curX + dx[j], ny = curY + dy[j];

                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(check[nx][ny] || board[nx][ny]) continue;

                check[nx][ny] = true;
                board[nx][ny] = num;
                a.push({num,nx,ny});
            }
        }
        temp = a;
    };


    while(s--)
        bfs();

    cout << board[x-1][y-1] ? board[x-1][y-1] : 0;
}

