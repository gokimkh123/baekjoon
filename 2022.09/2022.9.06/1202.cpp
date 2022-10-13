// 난이도 : 골드2, 유형 : 이진검색트리, 정렬, 그리디

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<string,string,string> tu;
typedef vector<pa> vc;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n, k, m, v, c, index = 0;
    ll ans = 0;
    vc store;
    multiset<int> C;

    cin >> n >> k;

    while(n--) {
        cin >> m >> v;
        store.emplace_back(m, v);
    }

    sort(all(store),[](pa a, pa b){
        return a.second > b.second;
    });

    while(k--){
        cin >> c;
        C.insert(c);
    }

    for(auto &i : store){
        auto it = C.lower_bound(i.first);

        if(it == C.end()) continue;

        ans += i.second;
        C.erase(it);
    }


    cout << ans;

}
