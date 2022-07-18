//난이도 : 실버3, 유형 : 구현, 수학

#include <iostream>
#include <vector>
#include <cmath>
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

unordered_map<int,int> map;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    double sum = 0,n;
    int ma = -4001,mi = 4001;cin >> n;

    vector<int> v(n);
    vector<p> ans;

    for(int i=0;i<n;i++){
        cin >> v[i];
        sum += v[i];
        ma = max(ma,v[i]);
        mi = min(mi,v[i]);
        map[v[i]]++;
    }
    sort(v.begin(),v.end());

    if(round(sum/n) == -0) cout << 0 << "\n";
    else cout << round(sum/n) << "\n";
    cout << v[n/2] << "\n";

    for(int i=mi;i<=ma;i++){
        if(!map[i]) continue;
        ans.push_back({map[i],i});
    }
    sort(ans.begin(),ans.end());

    if(ans.size() == 1) cout << ans[0].second << "\n";
    else{
        vector<int> t;
        int a = ans[ans.size()-1].first;
        t.push_back(ans[ans.size()-1].second);

        for(int i=0;i<ans.size()-1;i++){
            if(ans[i].first == a) t.push_back(ans[i].second);
        }
        sort(t.begin(),t.end());

        if(t.size() == 1) cout << t[0] << "\n";
        else cout << t[1] << "\n";
    }



    cout << v[n-1] - v[0];

}

