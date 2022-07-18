//난이도 : 골드4, 유형 : 우선순위 큐, 그리디

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef tuple<int,int,int> tu;
typedef vector<l> vc;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t;cin >> t;

    while(t--) {

        priority_queue<l, vc, greater<>> q;

        int n;
        l  a, b,ans = 0;

        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a;

            q.push(a);
        }

        while (1) {
            a = q.top();q.pop();
            b = q.top();q.pop();
            ans += a + b;

            if (q.empty()) {
                cout << ans << "\n";
                break;
            }
            q.push(a + b);

        }
    }
}

