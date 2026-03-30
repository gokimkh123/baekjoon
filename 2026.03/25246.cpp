#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    string s;
    cin >> s;

    size_t idx = s.find_last_of("aeiouAEIOU");

    cout << s.substr(0,idx + 1) << "ntry";
}