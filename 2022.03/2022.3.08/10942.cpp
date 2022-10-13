//난이도 : 골드3, 유형 : dp

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

bool dp[2002][2002];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,m;cin >> n;

    vector<int> v(n+1);

    for(int i=1;i<=n;i++){
        cin >> v[i];
        dp[i][i] = true;
    }

    for(int i=1;i<n;i++)
        if(v[i] == v[i+1]) dp[i][i+1] = true;


    for(int i=3;i<=n;i++){
        for(int j=1;j+i<=n+1;j++)
            if(v[i+j-1] == v[j] && dp[j+1][i+j-2]) dp[j][i+j-1] = true;
    }
    cin >> m;

    while(m--){
        int S,E;
        cin >> S >> E;
        cout << dp[S][E] << "\n";
    }

}
