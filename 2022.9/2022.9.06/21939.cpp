// 난이도 : 골드4, 유형 : 이진검색트리

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

    map<int, int> list_map;
    multiset<pa> list_set;

    string command;
    int n, m, p, l, x;

    cin >> n;

    while(n--){
        cin >> p >> l;

        list_set.insert({l, p});
        list_map[p] = l;
    }

    cin >> m;

    while(m--){
        cin >> command;

        if(command[0] == 'r'){
            cin >> x;
            auto MIN = list_set.begin();
            auto MAX = list_set.rbegin();
            if(x == 1) cout << MAX->second << "\n";
            else cout << MIN->second << "\n";
        }
        else if(command[0] == 'a'){
            cin >> p >> l;

            list_set.insert({l, p});
            list_map[p] = l;
        }
        else if(command[0] == 's'){
            cin >> p;
            list_set.erase({list_map[p], p});
            list_map.erase(p);
        }
    }

}
