#include <bits/stdc++.h>
using namespace std;

int check(char meC, char youC){
    if (meC == 'R' && youC == 'S') return 1;
    else if (meC == 'S' && youC == 'P') return 1;
    else if (meC == 'P' && youC == 'R') return 1;
    else if (meC == youC) return 0;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, ans = 0, temp = 0;

    cin >> n;

    string me, you;

    cin >> me >> you;

    for (int i = 0; i < n; i++) {
        int a = check(me[i], you[i]);
        if (a == 1) ans++;
        else if (a == -1) temp++;
    }
    ans > temp ? cout << "victory" : cout << "defeat";
}