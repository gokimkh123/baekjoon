//난이도 : 골드1, 유형 : 세그먼트 트리


#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<int>
using namespace std;

p init(int st,int en,int node,vc &v,vector<p> &tree){
    if(st == en){
        if(v[st] % 2 == 0) tree[node] = {1,0};
        else tree[node] = {0,1};
        return tree[node];
    }

    int mid = (st + en) / 2;

    p L = init(st,mid,node*2,v,tree);
    p R = init(mid+1,en,node*2+1,v,tree);

    return tree[node] = {L.first + R.first,L.second + R.second};
}

p Sum(int st,int en,int node,int L,int R,vc &v,vector<p> &tree){
    if(R < st || L > en) return {0,0};

    if(L <= st && en <= R) return tree[node];

    int mid = (st + en) / 2;

    p a = Sum(st,mid,node*2,L,R,v,tree);
    p b = Sum(mid+1,en,node*2+1,L,R,v,tree);

    return {a.first + b.first,a.second + b.second};
}


void Update(int st,int en,int node,int idx,int val,vc &v,vector<p> &tree){
    if(idx < st || idx > en) return;

    if(st == en){
        if(val % 2 == 0) tree[node] = {1,0};
        else tree[node] = {0,1};
        v[idx] = val;
        return;
    }

    int mid = (st + en) / 2;

    Update(st,mid,node*2,idx,val,v,tree);
    Update(mid+1,en,node*2+1,idx,val,v,tree);

    tree[node] = {tree[node*2].first + tree[node*2+1].first,tree[node*2].second + tree[node*2+1].second};
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,a,x,y;

    cin >> n;

    vc v(n);
    vector<p> tree(n*4);

    for(auto &i : v)
        cin >> i;

    init(0,n-1,1,v,tree);

    cin >> m;

    while(m--) {
        cin >> a >> x >> y;

        if (a == 1) Update(0, n - 1, 1, x - 1, y, v, tree);
        else if (a == 2) cout << Sum(0, n - 1, 1, x - 1, y - 1, v, tree).first << "\n";
        else cout << Sum(0, n - 1, 1, x - 1, y - 1, v, tree).second << "\n";

    }

}
