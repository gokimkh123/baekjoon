//난이도 : 골드1, 유형 : 세그먼트 트리

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<l>
using namespace std;

l init(int st,int en,int node,vc &v,vc &tree){
    if(st == en) return tree[node] = v[st];

    int mid = (st + en) / 2;

    return tree[node] = min(init(st,mid,node*2,v,tree),init(mid+1,en,node*2+1,v,tree));
}

l Search(int st,int en,int node,int L,int R,vc &v,vc &tree){
    if(L > en || R < st) return INF;

    if(L <= st && en <= R) return tree[node];

    int mid = (st + en) / 2;

    return min(Search(st,mid,node*2,L,R,v,tree),Search(mid+1,en,node*2+1,L,R,v,tree));
}

void Update(int st,int en,int node,int idx,l val,vc &v,vc &tree){
    if(idx < st || idx > en) return;

    if(st == en){
        tree[node] = v[idx] = val;
        return;
    }

    int mid = (st + en) / 2;

    Update(st,mid,node*2,idx,val,v,tree);
    Update(mid+1,en,node*2+1,idx,val,v,tree);

    tree[node] = min(tree[node*2],tree[node*2+1]);
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,M,a,i,j;
    cin >> n;

    vc tree(n*4),v(n);

    for(auto &x : v)
        cin >> x;

    init(0,n-1,1,v,tree);

    cin >> M;

    while(M--){

        cin >> a >> i >> j;

        if(a == 1) Update(0,n-1,1,i-1,j,v,tree);
        else cout << Search(0,n-1,1,i-1,j-1,v,tree) << "\n";
    }

}
