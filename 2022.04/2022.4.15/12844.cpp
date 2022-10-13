//난이도 : 플레3, 유형 : 세그먼트 트리, lazy propagation

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef tuple<int,int,int> tu;
typedef vector<int> vc;

l v[500001],tree[500001 * 4],lazy[500001 * 4];

void pg(int st,int en,int node){
    if(lazy[node]){
        tree[node] ^= ((en - st + 1) % 2) * lazy[node];

        if(st != en) lazy[node*2] ^= lazy[node],lazy[node*2+1] ^= lazy[node];

        lazy[node] = 0;
    }
}

l init(int st,int en,int node){
    if(st == en) return tree[node] = v[st];

    int mid = (st + en) / 2;

    return tree[node] = init(st,mid,node*2) ^ init(mid+1,en,node*2+1);
}

l XOR(int st,int en,int node,int L,int R){
    pg(st,en,node);
    if(R < st || L > en) return 0;
    if(L <= st && en <= R) return tree[node];

    int mid = (st + en) / 2;

    return XOR(st,mid,node*2,L,R) ^ XOR(mid+1,en,node*2+1,L,R);

}

void Update(int st,int en,int node,int L,int R,int val){
    pg(st,en,node);

    if(R < st || L > en) return;

    if(L <= st && en <= R){
        tree[node] ^= ((en - st + 1) % 2) * val;
        if(st != en) lazy[node*2] ^= val, lazy[node*2+1] ^= val;
        return;
    }

    int mid = (st + en) / 2;

    Update(st,mid,node*2,L,R,val);
    Update(mid+1,en,node*2+1,L,R,val);

    tree[node] = tree[node*2] ^ tree[node*2+1];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n,m,query,a,b,k;

    cin >> n;

    for(int i=0;i<n;i++)
        cin >> v[i];

    init(0,n-1,1);

    cin >> m;

    while(m--){
        cin >> query;

        if(query == 1){
            cin >> a >> b >> k;
            Update(0,n-1,1,a,b,k);
        }
        else{
            cin >> a >> b;
            cout << XOR(0,n-1,1,a,b) << "\n";
        }
    }
}

