//난이도 : 골드1, 유형 : 세그먼트 트리

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<int>
using namespace std;

vc MaxTree(100000*4),MinTree(100000*4),v;

int MaxInit(int st,int en,int node){
    if(st == en) return MaxTree[node] = v[st];

    int mid = (st + en) / 2;

    return MaxTree[node] = max(MaxInit(st,mid,node*2), MaxInit(mid+1,en,node*2+1));
}
int SearctMax(int st,int en,int node,int L,int R){
    if(L > en || R < st) return 0;

    if(L <= st && en <= R) return MaxTree[node];

    int mid = (st + en) / 2;

    return max(SearctMax(st,mid,node*2,L,R), SearctMax(mid+1,en,node*2+1,L,R));
}


int MinInit(int st,int en,int node){
    if(st == en) return MinTree[node] = v[st];

    int mid = (st + en) / 2;

    return MinTree[node] = min(MinInit(st,mid,node*2), MinInit(mid+1,en,node*2+1));
}
int SearctMin(int st,int en,int node,int L,int R){
    if(L > en || R < st) return INF;

    if(L <= st && en <= R) return MinTree[node];

    int mid = (st + en) / 2;

    return min(SearctMin(st,mid,node*2,L,R), SearctMin(mid+1,en,node*2+1,L,R));
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;

    cin >> n >> m;

    for(int i=0;i<n;i++){
        int a;cin >> a;v.push_back(a);
    }

    MaxInit(0,n-1,1);
    MinInit(0,n-1,1);
    while(m--){
        int a,b;
        cin >> a >> b;
        cout << SearctMin(0,n-1,1,a-1,b-1) << " " <<SearctMax(0,n-1,1,a-1,b-1) << "\n";

    }

}
