//난이도 : 골드4, 유형 : 크루스칼 알고리즘

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<int>
using namespace std;

int root[101];

int Find(int x){
    if(root[x] == x) return x;
    else return root[x] = Find(root[x]);
}

void Union(int x,int y){
    x = Find(x), y = Find(y);

    if(x < y) root[y] = x;
    else root[x] = y;
}

double d(double x1,double y1,double x2,double y2){
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,cnt = 0;
    double x,y,ans = 0;

    cin >> n;

    for(int i=0;i<n;i++)
        root[i] = i;

    pair<double,double> node[n];
    vector<tuple<double,int,int>> dist;

    for(int i=0;i<n;i++){
        cin >> x >> y;
        node[i] = {x,y};
    }


    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double temp = d(node[i].first,node[i].second,node[j].first,node[j].second);
            dist.push_back({temp,i,j});
        }
    }
    sort(dist.begin(),dist.end());

    for(int i=0;i<dist.size();i++){
        double a;
        int b,c;
        tie(a,b,c) = dist[i];

        if(Find(b) == Find(c)) continue;
        Union(b,c);
        ans += a;

        cnt++;
        if(cnt == n-1) break;
    }
    cout.precision(3);
    cout << ans;
}
