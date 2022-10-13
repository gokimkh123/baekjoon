//난이도 : 골드3, 유형 : Union-Find

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define mod
using namespace std;

int root[10001],ans[10001],cost[10001];

int Find(int x){
    if(root[x] == x) return x;
    else return root[x] = Find(root[x]);
}

void Union(int x,int y){
    x = Find(x), y = Find(y);

    if(x != y){
        if(ans[x] < ans[y]) swap(x,y);

        root[y] = x;
        ans[x] += ans[y];
    }
}

bool cmp(const p &a,const p &b){
    return a.first <= b.first;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,k;


    cin >> n >> m >> k;

    for(int i=1;i<=n;i++){
        root[i] = i;
        ans[i] = 1;
    }

    for(int i=1;i<=n;i++)
        cin >> cost[i];

    for(int i=0;i<m;i++){
        int v,w;
        cin >> v >> w;
        Union(v,w);
    }

    vector<p> v;

    for(int i=1;i<=n;i++){
        int parent = Find(i);

        v.push_back({parent,i});
    }

   sort(v.begin(),v.end(),cmp);

    int MIN = cost[v[0].second], temp = v[0].first, sum = 0,cnt = ans[v[0].first];
    for(int i=1;i<n;i++){
        if(temp != v[i].first){
            cnt += ans[v[i].first];
            sum += MIN;
            temp = v[i].first;
            MIN = cost[v[i].second];
        }
        else MIN = min(MIN,cost[v[i].second]);
    }
    sum += MIN;
    if(sum <= k && cnt == n) cout << sum;
    else cout << "Oh no";

}
