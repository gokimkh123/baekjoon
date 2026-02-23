#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &graph, vector<int> &check, int st, int c) {
    check[st] = c;
    for (auto &i : graph[st]) {
        if (!check[i]) {
            if (!dfs(graph, check, i, -c)) return false;
        }
        else if (check[i] == check[st])
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int k;
    cin >> k;

    while (k--) {

        bool ans = true;
        int v, e;
        cin >> v >> e;
        vector<vector<int>> graph(v + 1);
        vector<int> check(v + 1, 0);
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int i = 1; i <= v; i++) {
            if (!check[i]) {
                if (!dfs(graph, check, i, 1)) {
                    ans = false;
                    break;
                }
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }

}