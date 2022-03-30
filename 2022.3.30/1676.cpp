//난이도 : 실버4, 유형 : 수학

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<int>
#define F first
#define S second
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    l n,ans = 0;

    cin >> n;

    for(int i=5;i<=n;i++){
        if(i % 5 == 0) ans++;
        if(i % 25 == 0) ans++;
        if(i % 125 == 0) ans++;
    }

    cout << ans;
}

