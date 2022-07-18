//난이도 : 골드5, 유형 : UF

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

int root[1000001];

int Find(int x){
    if(root[x] == x)  return x;
    else return root[x] = Find(root[x]);
}

void Union(int x,int y){
    x = Find(x), y = Find(y);

    if(x == y) return;

    if(x < y) root[y] = x;
    else root[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t,m,n,k;
    cin >> t;
    for(int x=1;x<=t;x++){
        cin >> n;

        for(int i=0;i<n;i++)
            root[i] = i;

        cin >> k;

        for (int j = 0; j < k; j++) {
            int a, b;
            cin >> a >> b;
            Union(a, b);
        }

        cin >> m;
        cout << "Scenario " << x << ":\n";
        for(int j=0;j<m;j++) {
            int u, v;
            cin >> u >> v;
            if (Find(u) == Find(v)) cout << "1\n";
            else cout << "0\n";
        }
        cout << "\n";
    }
}

