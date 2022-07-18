//난이도 : 실버4, 유형 : dp

#include <bits/stdc++.h>
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef vector<double> vc;

double dp[10001],ans = -1.0;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;

    vc v(n+1);

    for(int i=1;i<=n;i++)
        cin >> v[i];

    for(int i=1;i<=n;i++)
        dp[i] = max(dp[i-1] * v[i],v[i]);

    for(int i=1;i<=n;i++)
        ans = max(ans,dp[i]);

    printf("%.3lf",ans);
}

