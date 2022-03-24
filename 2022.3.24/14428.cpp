//난이도 : 골드1, 유형 : 세그먼트 트리

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<int>
using namespace std;

p init(int st,int en,int node,vc &v,vector<p> &tree){
    if(st == en){
        tree[node].first = v[st];
        tree[node].second = st+1;
        return tree[node];
    }

    int mid = (st + en) / 2;

    p L = init(st,mid,node*2,v,tree);
    p R = init(mid+1,en,node*2+1,v,tree);

    if(L.first < R.first) return tree[node] = L;
    else if(L.first == R.first){
        if(L.second < R.second) return tree[node] = L;
        else return tree[node] = R;
    }
    else return tree[node] = R;
}

p Serach(int st,int en,int node,int L,int R,vc &v,vector<p> &tree){
    if(R < st || L > en) return {INF,INF};

    if(L <= st && en <= R) return tree[node];

    int mid = (st + en) / 2;

    p a = Serach(st,mid,node*2,L,R,v,tree);
    p b = Serach(mid+1,en,node*2+1,L,R,v,tree);

    if(a.first < b.first) return a;
    else if(a.first == b.first){
        if(a.second < b.second) return a;
        else return b;
    }
    else return b;

}

void Update(int st,int en,int node,int idx,int val,vc &v,vector<p> &tree){
    if(idx < st || idx > en) return;

    if(st == en){
        v[idx] = tree[node].first = val;
        tree[node].second = idx+1;
        return;
    }

    int mid = (st + en) / 2;

    Update(st,mid,node*2,idx,val,v,tree);
    Update(mid+1,en,node*2+1,idx,val,v,tree);

    if(tree[node*2].first > tree[node*2+1].first) tree[node] = tree[node*2+1];
    else if(tree[node*2].first == tree[node*2+1].first){
        if(tree[node*2].second < tree[node*2+1].second) tree[node] = tree[node*2];
        else tree[node] = tree[node*2+1];
    }
    else tree[node] = tree[node*2];
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

   while(m--){
       cin >> a >> x >> y;

       if(a == 1) Update(0,n-1,1,x-1,y,v,tree);
       else cout << Serach(0,n-1,1,x-1,y-1,v,tree).second << "\n";
   }
}
