//난이도 : 골드4, 유형 : 그리디


#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

vector<p> v;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,ans = 0;

    cin >> n;

    for(int i=0;i<n;i++){
        int a,b,c,d;cin >> a >> b >> c >> d;

        v.emplace_back(a*100+b,c*100+d);
    }

    sort(v.begin(),v.end());

    int date = 301,Mday = 0,idx = 0;

    while(date <= 1130){
        for(int i=idx;i<n;i++){
            if(v[i].first > date) break;
            if(v[i].second > Mday){
                Mday = v[i].second;
                idx = i;
            }
        }
        if(date == Mday){
            cout << "0";
            return 0;
        }
        date = Mday;
        ans++;
    }

    cout << ans;
}
