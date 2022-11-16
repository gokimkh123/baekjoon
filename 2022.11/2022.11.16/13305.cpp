// 난이도 : 실버3, 유형 : 그리디

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int, int> tu;
typedef vector<pa> vc;

ll n, dist[100001], cost[100001], idx, ans;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    
    cin >> n;

    for(int i=0;i<n-1;i++)
        cin >> dist[i];

    for(int i=0;i<n;i++)
        cin >> cost[i];


    ans = dist[0] * cost[0];

    for(int i=1;i<n-1;i++){
        if(cost[idx] * dist[i] > cost[i] * dist[i]) idx = i, ans += cost[i] * dist[i];
        else ans += cost[idx] * dist[i];
    }

    cout << ans;

}
