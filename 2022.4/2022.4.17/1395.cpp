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
typedef vector<bool> vc;

int tree[100001*4];
bool lazy[100001*4];

void pg(int st,int en,int node){
    if(lazy[node]){
        tree[node] = (en - st + 1) - tree[node];

        if(st != en)  lazy[node*2] = !lazy[node*2],lazy[node*2+1] = !lazy[node*2+1];

        lazy[node] = false;
    }
}
int Cnt(int st,int en,int node,int L,int R){
    pg(st,en,node);

    if(R < st || L > en) return 0;
    if(L <= st && en <= R) return tree[node];

    int mid = (st + en) / 2;

    return Cnt(st,mid,node*2,L,R) + Cnt(mid+1,en,node*2+1,L,R);
}

void Reverse(int st,int en,int node,int L,int R){
    pg(st,en,node);
    if(R < st || L > en) return;
    if(L <= st && en <= R){
        tree[node] = (en - st + 1) - tree[node];

        if(st != en) lazy[node*2] = !lazy[node*2],lazy[node*2+1] = !lazy[node*2+1];

        return;
    }

    int mid = (st + en) / 2;

    Reverse(st,mid,node*2,L,R);
    Reverse(mid+1,en,node*2+1,L,R);

    tree[node] = tree[node*2] + tree[node*2+1];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n,m,o,s,t;

    cin >> n >> m;

    while(m--){
        cin >> o >> s >> t;

        if(!o)  Reverse(0,n-1,1,s-1,t-1);
        else cout << Cnt(0,n-1,1,s-1,t-1) << "\n";
    }
}
