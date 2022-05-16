//난이도 : 플레3, 유형 : UF, 오프라인 쿼리, Set

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef tuple<int,int,int> tu;
typedef vector<tu> vc;

int parent[100001];
set<int> color[100001];

int Find(int x){
    return parent[x] == x ? x : parent[x] = Find(parent[x]);
}

void Union(int x,int y){
    x = Find(x), y = Find(y);

    if(x != y){
        if(color[x].size() <= color[y].size()) swap(x,y);

        parent[y] = x;

        for(auto &i : color[y])
            color[x].insert(i);

        color[y].clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    vc temp;
    vector<int> ans;

    int n,q,x,a;

    cin >> n >> q;

    parent[1] = 1;
    for(int i=2;i<=n;i++){
        cin >> a;
        parent[i] = a;
    }

    for(int i=1;i<=n;i++){
        cin >> a;
        color[i].insert(a);
    }

    for(int i=0;i<n-1+q;i++){
        cin >> x >> a;

        temp.emplace_back(x,a,parent[a]);
        if(x == 1) parent[a] = a;
    }

    for(int i=int(temp.size())-1;i>=0;i--){
        auto cur = temp[i];

        if(get<0>(cur) == 1) Union(get<1>(cur),get<2>(cur));
        else ans.push_back(color[Find(get<1>(cur))].size());
    }

    for(int i=int(ans.size())-1;i>=0;i--)
        cout << ans[i] << "\n";

}

