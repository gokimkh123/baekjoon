// 난이도 : 실버2, 유형 : dp

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int, int> tu;
typedef vector<ll> vc;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m, board[1001][1001] = {0, };

    cin >> n >> m;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> board[i][j];


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!i && !j) continue;
            else if(!i) board[i][j] += board[i][j - 1];
            else if(!j) board[i][j] += board[i - 1][j];
            else{
                if(board[i - 1][j] > board[i][j - 1]) board[i][j] += board[i - 1][j];
                else board[i][j] += board[i][j - 1];
            }
        }
    }

    cout << board[n - 1][m - 1];

}
