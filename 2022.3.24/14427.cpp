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
       cin >> a;

       if(a == 1){
           cin >> x >> y;
           Update(0,n-1,1,x-1,y,v,tree);
       }
       else cout << tree[1].second << "\n";
   }
/*
   for(auto &i : tree)
       cout << i.first << " " << i.second << "\n";*/
}
