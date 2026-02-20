#include <iostream>
#include <cmath>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    long long int n, ans;

    cin >> n;

    ans = pow(8, n);
    cout << ans;
}