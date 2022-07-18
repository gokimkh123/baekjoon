//난이도 : 골드2, 유형 : Union-Find

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define mod
using namespace std;

int gate[100001],root[100001];

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

    int G,P,ans = 0;
    cin >> G >> P;

    for(int i=1;i<=G;i++)
        root[i] = i;

    for(int i=1;i<=P;i++)
        cin >> gate[i];

    for(int i=1;i<=P;i++){
        int parent = Find(gate[i]);

        if(parent == 0){
            cout << ans;
            return 0;
        }

        ans++;
        Union(parent - 1,parent);
    }
    cout << ans;
}
