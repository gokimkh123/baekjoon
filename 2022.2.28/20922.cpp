//난이도 : 실버1, 유형 : 투포인터

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define mod
using namespace std;

int cnt[100001];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,k,ans = 0;
    cin >> n >> k;
    vector<int> v(n+1);

    for(int i=1;i<=n;i++)    cin >> v[i];

    int st = 1,en = 1;

    while(en - st >= 0 && en <= n){
        if(cnt[v[en]] < k){
            cnt[v[en]]++;en++;
        }
        else if(cnt[v[en]] >= k){
            cnt[v[st]]--;st++;
        }
        ans = max(ans,en - st);
    }


    cout << ans;

}
