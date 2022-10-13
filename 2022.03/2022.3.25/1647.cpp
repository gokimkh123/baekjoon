//난이도 : 골드4, 유형 : 크루스칼 알고리즘

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<int>
using namespace std;

unordered_map<double,int> root;

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

    int n,cnt = 0;
    double x,y,sum = 0;

    cin >> n;

    p node[1001];

    for(int i=0;i<n;i++){
        cin >> x >> y;

        node[i] = {x,y};
    }

    for(auto &i : node){


        if(cnt == n-1) break;
    }
}
