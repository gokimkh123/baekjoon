//난이도 : 플레4, 유형 : bfs, UF

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef tuple<int,int,int> tu;
typedef vector<int> vc;

int board[2001][2001],root[100001];
int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};

int Find(int x){
    if(root[x] == x) return x;
    else return root[x] = Find(root[x]);
}

void Union(int x,int y){
    x = Find(x), y = Find(y);

    if(x == y) return;
    else if(x < y) root[y] = x;
    else root[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    queue<p> q,temp;
    int n,k,x,y,ans = 0;

    cin >> n >> k;

    for(int i=1;i<=100000;i++)
        root[i] = i;

    auto civ = [&](){
        while(!q.empty()){
            auto cur = q.front();q.pop();

            for(int i=0;i<4;i++){
                int nx = dx[i] + cur.F, ny = dy[i] + cur.S;

                if(nx <= 0 || ny <= 0 || nx > n || ny > n) continue;

                if(!board[nx][ny]){
                    board[nx][ny] = board[cur.F][cur.S];
                    temp.push({nx,ny});
                }
                else{
                    if((board[cur.F][cur.S] == board[nx][ny]) || (Find(board[cur.F][cur.S]) == Find(board[nx][ny])))
                        continue;

                    Union(board[cur.F][cur.S],board[nx][ny]);
                    k--;
                }
            }
        }
    };

    auto Merge = [&](){
        while(!temp.empty()){
            auto cur = temp.front();
            q.push(cur);
            temp.pop();

            for(int i=0;i<4;i++){
                int nx = dx[i] + cur.F, ny = dy[i] + cur.S;

                if(nx <= 0 || ny <= 0 || nx > n || ny > n || !board[nx][ny]) continue;

                if((board[cur.F][cur.S] == board[nx][ny]) || (Find(board[cur.F][cur.S]) == Find(board[nx][ny])))
                    continue;

                Union(board[cur.F][cur.S],board[nx][ny]);
                k--;
            }
        }
    };

    for(int i=1;i<=k;i++){
        cin >> x >> y;

        board[x][y] = i;
        q.push({x,y});
        temp.push({x,y});
    }

    while(1) {

        Merge();

        if(k == 1){
            cout << ans;
            return 0;
        }
        civ();
        ans++;
    }
}
