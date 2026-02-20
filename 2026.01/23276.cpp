#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


    int k, ans = 1000000;
    cin >> k;

    while (k--) {
        int y, c1, c2;

        cin >> y >> c1 >> c2;

        int re = lcm(c1, c2), sum = y;

        while (sum < 2022)
            sum += re;

        ans = min(ans, sum);

    }
    cout << ans;

}