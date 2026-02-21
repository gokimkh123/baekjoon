#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        map<pair<int ,char>, int> card;
        map<char, vector<int>> temp;
        bool ch = false;

        for (int i = 0; i < 4; i++) {
            int a;
            char b;

            cin >> a >> b;

            card[{a, b}]++;
            temp[b].push_back(a);
        }

        // 같은 카드 숫자 3장 및 두장씩 짝 지은 카드
        int pair = 0;
        for (auto &p : card) {
            if (p.second >= 3) ch = true;
            else if (p.second == 2) pair++;
        }
        if (pair == 2) ch = true;

        for (auto &[c, v] : temp) {
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());

            if (v.size() >= 3) {
                for (size_t i = 0; i <= v.size() - 3; i++) {
                    // 3개의 숫자가 연속하는지 확인
                    if (v[i] + 1 == v[i+1] && v[i+1] + 1 == v[i+2]) {
                        ch = true;
                        break;
                    }
                }
            }
        }

        cout << (ch ? ":)" : ":(") << "\n";


    }

}