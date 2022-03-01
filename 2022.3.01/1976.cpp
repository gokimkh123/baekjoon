//난이도 : 골드4, 유형 : Union-Find


#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define mod
using namespace std;

int root[2001];

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

    int n,m;
    cin >> n >> m;

    for(int i=1;i<=n;i++)
        root[i] = i;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;cin >> x;

            if(x)   Union(i,j);
        }
    }
    int go;

    for(int i=0;i<m;i++){
        int city; cin >> city;
        if(i == 0) go = Find(city);
        else{
            if(go != Find(city)){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}
