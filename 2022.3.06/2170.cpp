//난이도 : 골드5, 유형 : 정렬,그리디

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

vector<p> v;
int ans;
bool cmp(const p &a,const p &b){
    if(a.first < b.first) return true;
    else if(a.first == b.first){
        return a.second < b.second;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,Xidx,Yidx;
    cin >> n;

    for(int i=0;i<n;i++){
        int x,y;cin >> x >> y;
        v.emplace_back(x,y);
    }
    sort(v.begin(),v.end(),cmp);

    Xidx = v[0].first, Yidx = v[0].second;

    for(int i=1;i<n;i++){
        if(v[i].first <= Yidx){
            Xidx = min(v[i].first,Xidx);
            Yidx = max(Yidx,v[i].second);
        }
        else{
            ans += (Yidx - Xidx);
            Xidx = v[i].first;
            Yidx = v[i].second;
        }
    }
    ans += (Yidx - Xidx);
    cout << ans;
}
