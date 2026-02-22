#include <bits/stdc++.h>
using namespace std;

inline int distcal(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t;

    cin >> t;


    while (t--) {
        queue<pair<int, int>> q;
        vector<tuple<int ,int ,int>> v;
        bool check[101] = {false};

        int n;
        bool ans = false;
        cin >> n;

        int stX, stY, enX, enY;
        cin >> stX >> stY;
        q.emplace(stX, stY);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            v.emplace_back(a, b, i);
        }

        cin >> enX >> enY;


        while (!q.empty()) {
            auto x = q.front();
            q.pop();

            if (distcal(x.first, x.second, enX, enY) <= 1000) {
                ans = true;
                break;
            }

            for (auto &[nx, ny, cnt] : v) {
                if (!check[cnt] && distcal(x.first, x.second, nx, ny) <= 1000) {
                    q.emplace(nx, ny);
                    check[cnt] = true;
                }
            }
        }

        cout << (ans ? "happy" : "sad") << "\n";
    }
}