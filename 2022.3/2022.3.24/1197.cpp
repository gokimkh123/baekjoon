//난이도 : 골드4, 유형 : 크루스칼 알고리즘

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<int>
using namespace std;

int root[10001];

int Find(int x){
    if(root[x] == x) return x;
    else return root[x] = Find(root[x]);
}

void Union(int x,int y){
    x = Find(x), y = Find(y);

    if(x < y) root[y] = x;
    else root[x] = y;
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

   int V,E,a,b,c,cnt = 0,ans = 0;

   cin >> V >> E;

   for(int i=1;i<=V;i++)
       root[i] = i;

   tuple<int,int,int> node[E];

   for(int i=0;i<E;i++){
       cin >> a >> b >> c;

       node[i] = {c,a,b};
   }

   sort(node,node + E);

   for(int i=0;i<E;i++){
       tie(c,a,b) = node[i];

       if(Find(a) == Find(b)) continue;

       Union(a,b);
       ans += c;
       cnt++;
       if(cnt == V-1) break;
   }
   cout << ans;
}
