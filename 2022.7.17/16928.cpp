// 난이도 : 골드5, 유형 : bfs

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

    int n,m,x,y,board[101]={0,};

    cin >> n >> m;

    for(int i=1;i<=n+m;i++){
        cin >> x >> y;
        board[x] = y;
    }

    auto bfs = [=](){
        int ans = 101 * 101, dist[101] = {0, };
        queue<int> q;
        q.push(1);

        while(!q.empty()){
            int now = q.front();q.pop();

            if(now == 100){
                ans = min(ans,dist[now]);
                continue;
            }

            for(int i=1;i<=6;i++){
                if(now + i > 100 || dist[now + i] || dist[board[now + i]]) continue;

                if(board[now + i]) q.push(board[now + i]),dist[board[now + i]] = dist[now] + 1;
                else q.push(now + i), dist[now + i] = dist[now] + 1;

            }
        }

        return ans;
    };

    cout << bfs();

}
