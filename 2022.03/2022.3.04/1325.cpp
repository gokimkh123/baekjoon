//난이도 : 실버1, 유형 : bfs

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

vector<int> grape[10001];

int bfs(int x){
    int check[10001] = {0, },cnt = 1;
    queue<int> q;
    q.push(x);
    check[x] = 1;

    while(!q.empty()){
        int num = q.front();q.pop();

        for(int i=0;i<grape[num].size();i++){
            if(!check[grape[num][i]]){
                check[grape[num][i]] = 1;
                cnt++;
                q.push(grape[num][i]);
            }
        }
    }
    return cnt;
}

bool cmp(const p &a, const p &b){
    if(a.first > b.first) return true;
    else if(a.first == b.first){
        if(a.second < b.second) return true;
        return false;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;

    while(m--){
        int a,b;
        cin >> a >> b;

        grape[b].push_back(a);
    }
    vector<p> ans;


    for(int i=1;i<=n;i++)
        ans.push_back({bfs(i),i});

    sort(ans.begin(),ans.end(),cmp);

    cout << ans[0].second << " ";
    for(int i=1;i<ans.size();i++){
        if(ans[i].first != ans[i-1].first) return 0;
        cout << ans[i].second << " ";
    }
}
