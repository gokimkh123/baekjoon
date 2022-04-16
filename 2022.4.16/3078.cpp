//난이도 : 골드3, 유형 : 큐, 슬라이딩 윈도우

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef tuple<int,int,int> tu;
typedef vector<int> vc;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    string s;
    int n,k;
    l ans = 0;
    queue<int> q[22];

    cin >> n >> k;

    for(int i=0;i<n;i++){
        cin >> s;

        int size = int(s.size());

        while(!q[size].empty() && i - q[size].front() > k)
            q[size].pop();

        ans += int(q[size].size());
        q[size].push(i);
    }

    cout << ans;

}

