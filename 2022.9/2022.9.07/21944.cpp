// 난이도 : 골드3, 유형 : 이진검색트리

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tu;
typedef vector<pa> vc;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    map<int, pa> list_map;    // key : 번호, value : 난이도, 분류
    multiset<pa> list_set[100001];    // 난이도, 번호, 분류
    multiset<int> list_set2[101];            // 난이도, 번호

    string command;
    int n, m, p, l, x, g;

    auto add = [&](){
        list_set[g].insert({l, p});
        list_set2[l].insert(p);
        list_map[p] = {l, g};
    };
    auto solved = [&](){
        list_set[list_map[p].second].erase({list_map[p].first, p});
        list_set2[list_map[p].first].erase(p);
        list_map.erase(p);
    };
    auto Recommend = [&](int type){
        if(type == 1){
            if(x == 1) cout << list_set[g].rbegin()->second << "\n";
            else cout << list_set[g].begin()->second << "\n";
        }
        else if(type == 2){
            if(x == 1){
                for(int i=100;i>=0;i--){
                    if(list_set2[i].empty()) continue;
                    cout << *(list_set2[i].rbegin()) << "\n";
                    break;
                }
            }
            else{
                for(int i=0;i<=100;i++){
                    if(list_set2[i].empty()) continue;
                    cout << *(list_set2[i].begin()) << "\n";
                    break;
                }
            }
        }
        else if(type == 3){
            int ans = -1;
            if(x == 1){
                for(int i=l;i<=100;i++){
                    if(list_set2[i].empty()) continue;
                    ans = *(list_set2[i].begin());
                    break;
                }
            }
            else{
                for(int i=l-1;i>=0;i--){
                    if(list_set2[i].empty()) continue;
                    ans = *(list_set2[i].rbegin());
                    break;
                }
            }

            cout << ans << "\n";
        }
    };


    cin >> n;

    while(n--){
        cin >> p >> l >> g;

        list_set2[l].insert(p);
        list_set[g].insert({l, p});
        list_map[p] = {l, g};
    }

    cin >> m;

    while(m--){
        cin >> command;

        if(command == "recommend"){
            cin >> g >> x;
            Recommend(1);
        }
        else if(command == "recommend2"){
            cin >> x;
            Recommend(2);
        }
        else if(command == "recommend3"){
            cin >> x >> l;
            Recommend(3);
        }

        else if(command[0] == 'a'){
            cin >> p >> l >> g;
            add();
        }
        else if(command[0] == 's'){
            cin >> p;
            solved();
        }
    }


}
