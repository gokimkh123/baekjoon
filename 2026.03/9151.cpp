#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    vector<int> tank1(55);
    vector<int> tank2(97);

    for (int i = 1; i<= 53; i++)
        tank1[i] = i * i * i;
    for (int i = 1; i<= 95; i++)
        tank2[i] = (i * (i + 1) * (i + 2)) / 6;

    while (true) {
        int a, ans = -1;
        cin >> a;

        if (a == 0) break;

        for (int i = 1; i <= 53; i++) {
            if (tank1[i] > a) break;
            ans = max(ans, tank1[i]);
        }

        for (int i = 1; i <= 95; i++) {
            if (tank2[i] > a) break;
            ans = max(ans, tank2[i]);
        }


        for (int i = 1; i <= 53; i++) {
            for (int j = 1; j <= 95; j++) {
                if (tank1[i] + tank2[j] > a) break;

                ans = max(ans, tank1[i] + tank2[j]);
            }
        }
        cout << ans << endl;
    }
}