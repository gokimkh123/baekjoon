//난이도 : 골드1, 유형 : 세그먼트 트리

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<l>
using namespace std;

const int mod = 1000000007;

l init(int st,int en,int node,vc &tree,vc &v){
    if(st == en) return tree[node] = v[st];

    int mid = (st + en) / 2;

    return tree[node] = ((init(st,mid,node*2,tree,v) % mod) * (init(mid+1,en,node*2+1,tree,v)) % mod) % mod;
}

l Sum(int st,int en,int node,int L,int R,vc &tree,vc &v){
    if(L > en || R < st) return 1;

    if(L <= st && en <= R) return tree[node];

    int mid = (st + en) / 2;

    return ((Sum(st,mid,node*2,L,R,tree,v) % mod) * (Sum(mid+1,en,node*2+1,L,R,tree,v)) % mod) % mod;
}

void Update(int st,int en,int node,int idx,l val,vc &tree,vc &v){
    if(idx < st || idx > en) return;

    if(st == en){
        tree[node] = v[idx] = val;
        return;
    }

    int mid = (st + en) / 2;

    Update(st,mid,node*2,idx,val,tree,v);
    Update(mid+1,en,node*2+1,idx,val,tree,v);

    tree[node] = ((tree[node*2] % mod) * (tree[node*2+1] % mod)) % mod;
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,k,a,b;
    l c;

    cin >> n >> m >> k;

    vc tree(n*4);
    vc v(n);

    for(auto &i : v)
        cin >> i;

    init(0,n-1,1,tree,v);

    for(int x=0;x<m+k;x++){
        cin >> a >> b >> c;

        if(a == 1) Update(0,n-1,1,b-1,c,tree,v);
        else if(a == 2) cout << Sum(0,n-1,1,b-1,c-1,tree,v) % mod << "\n";
    }

}
