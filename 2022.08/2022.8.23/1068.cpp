// 난이도 : 골드5, 유형 : 트리, dfs

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tu;
typedef vector<int> vc;

int Erase;
vector<int> tree[52];

int dfs(int cur){
    int cnt = 1, child = 0;

    for(auto next : tree[cur]){
        if(Erase == next) continue;
        child += dfs(next);
    }

    if(child) return child;
    else return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n, par, root;

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> par;

        if(par + 1 == 0) root = i + 1;

        tree[par + 1].push_back(i + 1);
    }

    cin >> Erase;

    Erase++;
    
    if(Erase == root) cout << "0";
    else cout << dfs(root);

}

