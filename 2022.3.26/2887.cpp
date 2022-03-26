//난이도 : 골드1, 유형 : 크루스칼 알고리즘

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<int>
#define F first
#define S second
using namespace std;

int root[100001];

int Find(int x){
    if(root[x] == x) return x;
    else return root[x] = Find(root[x]);
}

void Union(int x,int y){
    x = Find(x), y = Find(y);

    if(x < y) root[y] = x;
    else root[x] = y;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,a,b,c,ans = 0;

    cin >> n;

    p x[n],y[n],z[n];

    vector<tuple<int,int,int>> v;

    for(int i=0;i<n;i++) {
        cin >> a >> b >> c;
        root[i] = i;

        x[i] = {a,i};
        y[i] = {b,i};
        z[i] = {c,i};
    }

    sort(x,x+n);
    sort(y,y+n);
    sort(z,z+n);

    for(int i=0;i<n-1;i++){
        v.emplace_back(x[i+1].F - x[i].F,x[i].S,x[i+1].S);
        v.emplace_back(y[i+1].F - y[i].F,y[i].S,y[i+1].S);
        v.emplace_back(z[i+1].F - z[i].F,z[i].S,z[i+1].S);
    }

    sort(v.begin(),v.end());

    for(auto &i : v){
        tie(a,b,c) = i;

        if(Find(b) == Find(c)) continue;
        Union(b,c);

        ans += a;
    }

    cout << ans;
}
