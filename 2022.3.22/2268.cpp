//난이도 : 골드1, 유형 : 세그먼트 트리

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<l>
using namespace std;

l Sum(int st,int en,int node,int L,int R,vc &tree){
    if(R < st || L > en) return 0;

    if(L <= st && en <= R) return tree[node];

    int mid = (st + en) / 2;

    return Sum(st,mid,node*2,L,R,tree) + Sum(mid+1,en,node*2+1,L,R,tree);
}

void Update(int st,int en,int node,int idx,l val,vc &tree){
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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,i,j,k;
    cin >> n >> m;

    vc tree(n*4,0);

    while(m--){
        cin >> i >> j >> k;

        if(i == 0){
            if(j > k) swap(j,k);
        }

        if(i == 0) cout << Sum(0,n-1,1,j-1,k-1,tree) << "\n";
        else Update(0,n-1,1,j-1,k,tree);
    }
}
