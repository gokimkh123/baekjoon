#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    char board[101][101];

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }
    pair<int, int> a,b,c,d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '#') {

                if (j + 1 < m) {
                    // 왼쪽 상단
                    if (i + 1 < n && board[i][j + 1] == '#' && board[i + 1][j] == '#') a = {i, j};
                    // 왼쪽 하단
                    else if (i - 1 >= 0 && board[i][j + 1] == '#' && board[i - 1][j] == '#') b = {i, j};
                }

                if (j - 1 >= 0) {
                    //오른쪽 상단
                    if (i + 1 < n && board[i][j - 1] == '#' && board[i + 1][j] == '#') c = {i, j};
                    // 오른쪽 하단
                    else if (i - 1 >= 0 && board[i][j - 1] == '#' && board[i - 1][j] == '#') d = {i, j};
                }
            }
        }
    }

    // a왼쪽 상단, c오른쪽 상단 비교
    // b, d비교

    if (board[a.first][(a.second + c.second) / 2] == '.') cout << "UP";
    else if (board[(a.first + b.first) / 2][a.second] == '.') cout << "LEFT";
    else if (board[b.first][(b.second + d.second) / 2] == '.') cout << "DOWN";
    else if ( board[(c.first + d.first) / 2][c.second] == '.') cout << "RIGHT";

}