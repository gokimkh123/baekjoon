//난이도 : 실버4, 유형 : dp

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<p>
#define F first
#define S second
using namespace std;

int dp[50001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,temp;

    cin >> n;

    dp[1] = 1;

    for(int i=2;i<=n;i++){
        int MIN = INF;
        for(int j=1;j*j<=i;j++){
            temp = i - j * j;

            MIN = min(MIN,dp[temp]);
        }
        dp[i] = MIN + 1;
    }
    cout << dp[n];
}

