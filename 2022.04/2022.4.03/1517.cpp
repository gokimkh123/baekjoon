//난이도 : 플레5, 유형 : 세그먼트 트리

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<int>
#define F first
#define S second
using namespace std;

int Cnt(int st,int en,int node,int L,int R,vc &tree){
    if(R < st || L > en) return 0;

    if(L <= st && en <= R) return tree[node];

    int mid = (st + en) / 2;

    return Cnt(st,mid, node*2,L,R,tree) + Cnt(mid+1,en,node*2+1,L,R,tree);

}

void Update(int st,int en,int node,int idx,int val,vc &tree){
    if(idx < st || idx > en) return;

    if(st == en){
        tree[node] = val;
        return;
    }

    int mid = (st + en) / 2;

    Update(st,mid,node*2,idx,val,tree);
    Update(mid+1,en,node*2+1,idx,val,tree);

    tree[node] = tree[node*2] + tree[node*2+1];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    l ans = 0;
    int n;
    cin >> n;

    vc tree(n*4,0);
    vector<p> v;

    for(int i=0;i<n;i++){
        int x;cin >> x;

        v.emplace_back(x,i);
    }

    sort(v.begin(),v.end());

    for(int i=0;i<n;i++){
        ans += Cnt(0,n-1,1,v[i].second + 1,n-1,tree);
        Update(0,n-1,1,v[i].S,1,tree);
    }
    cout << ans;
}

