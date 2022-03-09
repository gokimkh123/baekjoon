//난이도 :  골드4, 유형 : UF

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

int root[500001];

int Find(int x){
    if(root[x] == x) return x;
    else return root[x] = Find(root[x]);
}

void Union(int x,int y){
    x = Find(x), y = Find(y);

    if(x == y) return;

    if(x < y) root[y] = x;
    else root[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,m,idx = -1;
    cin >> n >> m;

    for(int i=0;i<n;i++)
        root[i] = i;

    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;

        if(idx != -1) continue;
        if(Find(a) == Find(b)) idx = i+1;
        else Union(a,b);
    }
    idx != -1 ? cout << idx : cout << 0;
}


