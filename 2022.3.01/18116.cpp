//난이도 : 골드4, 유형 : Union-Find

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define mod
using namespace std;

int ans[1000001],root[1000001];

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

    char a;
    int n,b,c;
    cin >> n;

    for(int i=1;i<=1000000;i++){
        root[i] = i;
        ans[i] = 1;
    }

    for(int i=0;i<n;i++){
        cin >> a;

        if(a == 'I'){
            cin >> b >> c;
            Union(b,c);
        }
        else if(a == 'Q'){
            cin >> b;
            cout << ans[Find(b)] << "\n";
        }
    }

}
