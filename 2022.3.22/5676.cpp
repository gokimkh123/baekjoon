//난이도 : 골드1, 유형 : 세그먼트 트리

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<l>
using namespace std;

l init(int st,int en,int node,vc &v,vc &tree){
    if(st == en){
        if(v[st] < 0) tree[node] = -1;
        else if(v[st] > 0) tree[node] = 1;
        else tree[node] = 0;
        return tree[node];
    }

    int mid = (st + en) / 2;

    return tree[node] = init(st,mid,node*2,v,tree) * init(mid+1,en,node*2+1,v,tree);
}

l mul(int st,int en,int node,int L,int R,vc &v,vc &tree){
    if(R < st || L > en) return 1;

    if(L <= st && en <= R) return tree[node];

    int mid = (st + en) / 2;

    return mul(st,mid,node*2,L,R,v,tree) * mul(mid+1,en,node*2+1,L,R,v,tree);
}


void Update(int st,int en,int node,int idx,l val,vc &v,vc &tree){
    if(idx < st || idx > en) return;

    if(st == en){
        if(val < 0) tree[node] = v[idx] = -1;
        else if(val > 0) tree[node] = v[idx] = 1;
        else tree[node] = v[idx] = 0;
        return;
    }

    int mid = (st + en) / 2;

    Update(st,mid,node*2,idx,val,v,tree);
    Update(mid+1,en,node*2+1,idx,val,v,tree);

    tree[node] = tree[node*2] * tree[node*2+1];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k,x,y;
    char a;

    while(cin >> n >> k){
        vc v(n),tree(n*4);

        for(auto &i : v)
            cin >> i;

        init(0,n-1,1,v,tree);

        while(k--){
            cin >> a >> x >> y;

            if(a == 'C') Update(0,n-1,1,x-1,y,v,tree);
            else{
                l temp = mul(0,n-1,1,x-1,y-1,v,tree);
                if(temp < 0) cout << "-";
                else if(temp > 0) cout << "+";
                else cout << "0";
            }
        }
        cout << "\n";
    }

}
