#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100000;
int Move[SIZE + 2];
void bfs(int n, int k) {
    int check[SIZE + 2] = {0}, ans = SIZE * 10;

    check[n] = 0;

    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == k) ans = min(ans, check[cur]);

        if (cur + 1 <= SIZE && !check[cur + 1]) {
            check[cur + 1] = check[cur] + 1;
            Move[cur + 1] = cur;
            q.push(cur + 1);
        }
        if (cur - 1 >= 0 && !check[cur - 1]) {
            check[cur - 1] = check[cur] + 1;
            Move[cur - 1] = cur;
            q.push(cur - 1);
        }
        if (cur * 2 <= SIZE && !check[cur * 2]) {
            check[cur * 2] = check[cur] + 1;
            Move[cur * 2] = cur;
            q.push(cur * 2);
        }
    }
    vector<int> path;
    for (int i = k; i != n; i = Move[i])
        path.push_back(i);
    path.push_back(n);
    cout << ans << "\n";
    reverse(path.begin(), path.end());
    for (auto i : path)
        cout << i << " ";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


    int n, k;

    cin >> n >> k;

    bfs(n, k);
}
