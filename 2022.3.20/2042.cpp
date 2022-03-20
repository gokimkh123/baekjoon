난이도 : 골드1, 유형 : 세그먼트 트리

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<l>
using namespace std;

l init(int st,int en,int node,vc &tree,vc &num){
    if(st == en) return tree[node] = num[st];
    int mid = (st + en) / 2;

    return tree[node] = init(st,mid,node*2,tree,num) + init(mid+1,en,node*2+1,tree,num);
}
l Sum(int st,int en,int node,int L,int R,vc &tree,vc &num){
    if(L > en || R < st) return 0;
    if(L <= st && en <= R) return tree[node];

    int mid = (st + en) / 2;
    return Sum(st,mid,node*2,L,R, tree,num) + Sum(mid+1,en,node*2+1,L,R,tree,num);
}

void Update(int st,int en,int node,int idx,l val,vc &tree,vc &num){
    if(idx < st || idx > en) return;

    if(st == en){
        num[idx] = tree[node] = val;
        return;
    }

    int mid = (st + en) / 2;

    Update(st,mid,node*2,idx,val,tree,num);
    Update(mid+1,en,node*2+1,idx,val,tree,num);
    tree[node] = tree[node*2] + tree[node*2+1];
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,k,a,b;
    l c;
    cin >> n >> m >> k;

    vc num(n);
    vc tree(n*4);

    for(auto &i : num) cin >> i;

    init(0,n-1,1,tree,num);

    for(int x=0;x<m+k;x++){
        cin >> a >> b >> c;

        if(a == 1) Update(0,n-1,1,b-1,c,tree,num);
        else if(a == 2) cout << Sum(0,n-1,1,b-1,c-1,tree,num) << "\n";
    }

}
