#include <bits/stdc++.h>
using namespace std;

int dl[] = {0, 0, 0, 0, 1, -1};
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int L, R, C;

int bfs(string (&board)[31][31], tuple<int, int, int> st, tuple<int, int, int> en) {
    int check[31][31][31] = {0};
    int ans = 123456789;
    queue<tuple<int, int, int>> q;
    auto [l, x, y] = st;

    check[l][x][y] = 0;
    q.emplace(l, x, y);

    while (!q.empty()) {
        auto [l, x, y] = q.front();
        q.pop();

        if (board[l][x][y] == 'E') ans = min(ans, check[l][x][y]);

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i], ny = y + dy[i], nl = l + dl[i];

            if (check[nl][nx][ny] || nl < 0 || nl >= L || nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (board[nl][nx][ny] == '#') continue;

            check[nl][nx][ny] = check[l][x][y] + 1;
            q.emplace(nl, nx, ny);

        }
    }

    return ans;
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    while (true) {
        string board[31][31];
        tuple<int, int, int> st;
        tuple<int, int, int> en;
        cin >> L >> R >> C;

        if (L == 0 && R == 0 && C == 0) break;

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                cin >> board[i][j];
                for (int k = 0; k < C; k++) {
                    if (board[i][j][k] == 'S') st = {i, j, k};
                    else if (board[i][j][k] == 'E') en = {i, j, k};
                }
            }
        }


        int ans = bfs(board, st, en);

        if (ans == 123456789) cout << "Trapped!\n";
        else cout << "Escaped in " << ans << " minute(s)." << "\n";
    }



}
