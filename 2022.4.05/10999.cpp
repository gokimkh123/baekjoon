//난이도 : 플레4, 유형 : 세그먼트 트리,lazy Propagation

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<l>
#define F first
#define S second
using namespace std;

l arr[1000001],tree[1000001 * 4],lazy[1000001 * 4];

void pg(int st,int en,int node){
    if(lazy[node]){
        tree[node] += (en - st + 1) * lazy[node];
        if(st != en) lazy[node*2] += lazy[node],lazy[node*2+1] += lazy[node];
        lazy[node] = 0;
    }
}

l init(int st,int en,int node){
    if(st == en) return tree[node] = arr[st];

    int mid = (st + en) / 2;
    return tree[node] = init(st,mid,node*2) + init(mid+1,en,node*2+1);
}

l sum(int st,int en,int node,int L,int R){
    pg(st,en,node);

    if(R < st || L > en) return 0;
    if(L <= st && en <= R) return tree[node];

    int mid = (st + en) / 2;
    return sum(st,mid,node*2,L,R) + sum(mid+1,en,node*2+1,L,R);
}

void Update(int st,int en,int node,int L,int R,l val){
    pg(st,en,node);

    if(R < st || L > en) return;

    if(L <= st && en <= R){

        tree[node] += (en - st + 1) * val;
        if(st != en) lazy[node*2] += val,lazy[node*2+1] += val;

        return;
    }

    int mid = (st + en) / 2;

    Update(st,mid,node*2,L,R,val);
    Update(mid+1,en,node*2+1,L,R,val);

    tree[node] = tree[node*2] + tree[node*2+1];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n,m,k,a,b,c;
    l d;
    cin >> n >> m >> k;

    for(int i=0;i<n;i++)
        cin >> arr[i];

    init(0,n-1,1);

    for(int i=0;i<m+k;i++){
        cin >> a;

        if(a == 1){
            cin >> b >> c >> d;
            Update(0,n-1,1,b-1,c-1,d);
        }
        else{
            cin >> b >> c;
            cout << sum(0,n-1,1,b-1,c-1) << "\n";
        }
    }

}

