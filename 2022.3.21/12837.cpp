//난이도 : 골드1, 유형 : 세그먼트 트리

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<l>
using namespace std;

l Sum(int st,int en,int node,int L,int R,vc &v,vc &tree){
    if(L > en || R < st) return 0;

    if(L <= st && en <= R) return tree[node];

    int mid = (st + en) / 2;

    return Sum(st,mid,node*2,L,R,v,tree) + Sum(mid+1,en,node*2+1,L,R,v,tree);
}

void Update(int st,int en,int node,int idx,l val,vc &v,vc &tree){
    if(idx < st || idx > en) return;

    if(st == en){
        tree[node] += val;
        v[idx] += val;
        return;
    }

    int mid = (st + en) / 2;

    Update(st,mid,node*2,idx,val,v,tree);
    Update(mid+1,en,node*2+1,idx,val,v,tree);

    tree[node] = tree[node*2] + tree[node*2+1];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,Q,a,b;
    l c;
    cin >> n >> Q;

    vc v(n),tree(n*4);

    while(Q--){
        cin >> a >> b >> c;

        if(a == 1) Update(0,n-1,1,b-1,c,v,tree);
        else cout << Sum(0,n-1,1,b-1,c-1,v,tree) << "\n";
    }

}
