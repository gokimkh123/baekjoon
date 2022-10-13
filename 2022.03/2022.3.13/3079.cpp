//난이도 : 골드5, 유형 : 이분탐색, 파라미터 서치

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    l n,m,ans = INF * 1000000000 + 1;

    cin >> n >> m;

    vector<l> v(n);

    for(int i=0;i<n;i++)
        cin >> v[i];

    sort(v.begin(),v.end());

    l st = 1, en = v[n-1] * m;

    while(en - st >= 0){
        l mid = (en + st) / 2,sum = 0;

        for(auto &i : v)
            sum += (mid / i);

        if(sum >= m){
            en = mid - 1;
            ans = min(ans,mid);
        }
        else st = mid + 1;
    }
    cout << ans;
}

