//난이도 : 플레4, 유형 : 오프라인 쿼리, UF

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

int parent[200001];

int Find(int x){
    return parent[x] == x ? x : parent[x] = Find(parent[x]);
}

void Union(int x,int y){
    x = Find(x), y = Find(y);

    if(x != y) parent[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    stack<tu> temp;
    stack<string> ans;

    int n,q,x,a,b;

    cin >> n >> q;

    parent[1] = 1;
    for(int i=2;i<=n;i++){
        cin >> a;
        parent[i] = a;
    }

    for(int i=0;i<q+n-1;i++){
        cin >> x;

        if(!x){
            cin >> a;
            temp.push({0,a,parent[a]});
            parent[a] = a;
        }
        else{
            cin >> a >> b;
            temp.push({1,a,b});
        }
    }

    while(!temp.empty()){
        auto cur = temp.top();temp.pop();

        if(get<0>(cur)) Find(get<1>(cur)) == Find(get<2>(cur)) ? ans.push("YES") : ans.push("NO");
        else Union(get<1>(cur),get<2>(cur));
    }

    while(!ans.empty()){
        cout << ans.top() << "\n";
        ans.pop();
    }
}

