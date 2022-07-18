// 난이도 : 골드4, 유형 : bfs

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

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n,board[51][51] = {0, },dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};
    cin >> n;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;

        for(int j=0;j<s.size();j++)
            board[i][j] = s[j] - 48;
    }

    auto bfs = [=](){
        int ans = 50 * 50 + 1;
        bool check[51][51][50*50+1] = {0, };
        queue<tu> q;

        q.push({0,0,0});
        check[0][0][0] = true;

        while(!q.empty()){
            int nx,ny,cnt;
            tie(nx,ny,cnt) = q.front();q.pop();
            if(nx == n - 1 && ny == n - 1){
                ans = min(ans,cnt);
                continue;
            }

            for(int i=0;i<4;i++){
                int x = dx[i] + nx, y = dy[i] + ny;

                if(x < 0 || y < 0 || x >= n || y >= n || check[x][y][cnt]) continue;

                if(!board[x][y] && !check[x][y][cnt+1]){
                    q.push({x,y,cnt+1});
                    check[x][y][cnt+1] = true;
                }
                else if(board[x][y] && !check[x][y][cnt]){
                    q.push({x,y,cnt});
                    check[x][y][cnt] = true;
                }
            }
        }

        return ans;
    };

    int ans = bfs();

    cout << ans;
}
