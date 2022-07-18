//난이도 : 실버3, 유형 : 정렬

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <deque>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

bool cmp(const p &a,const p &b){
    return a.second > b.second;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<int> v;
    vector<pair<int,int>> ans;
    int n, c;
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        int a;cin >> a;v.push_back(a);
    }

    for(int i=0;i<n;i++){
        int cnt = 1;
        if(v[i] == -1) continue;
        for(int j=i+1;j<n;j++){
            if(v[i] == v[j]) {
                cnt++;
                v[j] = -1;
            }
        }
        ans.push_back({v[i],cnt});
    }
    stable_sort(ans.begin(),ans.end(),cmp);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].second;j++)
            cout << ans[i].first << " ";
    }
}

