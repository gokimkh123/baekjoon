//난이도 : 골드4, 유형 : UF, map

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

unordered_map<int,int> root;
bool check[51];

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
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n,m,k,a;

    cin >> n >> m >> k;

    for(int i=1;i<=n;i++)
        root[i] = i;

    vc save[51];

    for(int i=0;i<k;i++){
        cin >> a;
        check[a] = true;
        root[a] = -1;
    }
    root[-1] = -1;

    for(int z=0;z<m;z++){
        cin >> k;

        for(int i=0;i<k;i++){
            cin >> a;
            if(check[a]) save[z].push_back(-1);
            else save[z].push_back(a);
        }

        int size = int(save[z].size());

        for(int i=0;i<size-1;i++)
            Union(save[z][i],save[z][i+1]);

    }

    int temp = m;

    for(int i=0;i<temp;i++)
        if(Find(save[i][0]) == -1) m--;

    cout << m;


}
