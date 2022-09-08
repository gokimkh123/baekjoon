// 난이도 : 골드3, 유형 : 이진탐색트리

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tu;
typedef vector<int> vc;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n, q, a, query, release, x, state = 1;
    set<int> tour;
    cin >> n >> q;

    for(int i=1;i<=n;i++){
        cin >> a;
        if(a) tour.insert(i);
    }

    while(q--){
        cin >> query;

        if(query == 1){
            cin >> release;

            if(tour.find(release) != tour.end()) tour.erase(release);
            else tour.insert(release);
        }
        else if(query == 2){
            cin >> x;

            state = (state + x - 1) % n + 1;
        }
        else if(query == 3){
            if(tour.empty()) cout << "-1\n";
            else{
                auto it = tour.lower_bound(state);
                if(it != tour.end())  cout << *it - state << "\n";
                else cout << n - state + *tour.begin() << "\n";
            }
        }
    }
}
