//난이도 : 골드1, 유형 : 세그먼트 트리

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<int>
using namespace std;

int init(int st,int en,int node,vc &v,vc &tree){
    if(st == en) return tree[node] = v[st];

    int mid = (st + en) / 2;

    return tree[node] = min(init(st,mid,node*2,v,tree),init(mid+1,en,node*2+1,v,tree));
}

int Search(int st,int en,int node,int L,int R,vc &v,vc &tree){
    if(L > en || R < st) return INF;

    if(L <= st && en <= R) return tree[node];

    int mid = (st + en) / 2;

    return min(Search(st,mid,node*2,L,R,v,tree), Search(mid+1,en,node*2+1,L,R,v,tree));
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,a,b;

    cin >> n >> m;

    vc v(n),tree(n*4);

    for(auto &i : v)
        cin >> i;

    init(0,n-1,1,v,tree);

    while(m--){
        cin >> a >> b;

        cout << Search(0,n-1,1,a-1,b-1,v,tree) << "\n";
    }

}
