//난이도 : 골드4, 유형 : UF

#include <bits/stdc++.h>
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef tuple<int,int,int> tu;
typedef vector<tu> vc;

int root[100001];

int Find(int x){
    if(root[x] == x) return x;
    else return root[x] = Find(root[x]);
}

void Union(int x,int y){
    x = Find(x), y = Find(y);

    if(x < y) root[y] = x;
    else root[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n,m,a,b,c,st,en;

    vc v;

    cin >> n >> m;

    for(int i=1;i<=n;i++)
        root[i] = i;

    while(m--){
        cin >> a >> b >> c;
        v.emplace_back(c,a,b);
    }

    sort(v.begin(),v.end(),[](tu a,tu b){
        return get<0>(a) > get<0>(b);
    });

    cin >> st >> en;


    for(auto &i : v){
        tie(c,a,b) = i;
        Union(a,b);
        if(Find(st) == Find(en)){
            cout << c;
            return 0;
        }
    }
}

