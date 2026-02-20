#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    long long int n, ans = 1;
    cin >> n;

    for (long long int i = 1; i <= n; i++) {
        ans = i * ans;
    }

    cout << ans;
}