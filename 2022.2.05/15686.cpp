// 난이도 : 골드 5, 유형 : 완전탐색, 시뮬레이션

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#define l long long
using namespace std;

int n,m,city[53][53];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<pair<int,int>> hou;
    vector<pair<int,int>> ken;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
            if (city[i][j] == 2) ken.push_back({i,j});
            else if(city[i][j] == 1) hou.push_back({i,j});
        }
    }
    vector<int> v(ken.size(),1);
    fill(v.begin(),v.begin() + ken.size() - m,0);


    int ans = 1000001;

    do{
        int dist = 0;
        for(auto &x : hou) {
            int temp = 1000001;
            for (int i = 0; i < ken.size(); i++) {
                if (!v[i]) continue;
                temp = min(temp,abs(x.first - ken[i].first) + abs(x.second - ken[i].second));
            }
            dist += temp;
        }
        ans = min(dist,ans);
    }while(next_permutation(v.begin(),v.end()));

    cout << ans;
}

