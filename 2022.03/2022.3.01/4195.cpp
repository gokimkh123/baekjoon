//난이도 : 골드2, 유형 : Union-Find, map

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define mod
using namespace std;

int root[200001],ans[200001];

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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;cin >> t;

    while(t--){
        int n,idx = 1;
        cin >> n;

        for(int i=1;i<=200000;i++){
            ans[i] = 1;
            root[i] = i;
        }

        unordered_map<string,int> M;

        for(int i=0;i<n;i++){
            string a,b; cin >> a >> b;

            if(!M[a]) M[a] = idx++;
            if(!M[b]) M[b] = idx++;

            Union(M[a],M[b]);

            int parenta = Find(M[a]);

            cout << ans[parenta] << "\n";
        }




    }
}
