#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


    while (true) {
        unordered_map<char, int> m;
        string s;
        cin >> s;
        if (s == "#") break;

        for (auto i : s)
            m[i]++;

        if (m['A'] >= double(s.length() / 2.0)) cout << "need quorum\n";
        else if (m['Y'] > m['N']) cout << "yes\n";
        else if (m['Y'] < m['N']) cout << "no\n";
        else cout << "tie\n";
    }
}