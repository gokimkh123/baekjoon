// 난이도 : 실버 4, 유형 : 구현,정렬

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#define l long long
#define INF 1e9
using namespace std;

bool cmp(tuple<int,int,char> u, tuple<int,int,char> v){
    if(get<1>(u) < get<1>(v)) return true;
    else if(get<1>(u) == get<1>(v)){
        if(get<0>(u) < get<0>(v)) return true;
        return false;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<tuple<int,int,char>> v;

    int n,m;cin >> n >> m;

    for(int i=0;i<m;i++){
        char c;
        int a,b;cin >> a >> b >> c;

        v.push_back({a,b,c});
    }

    sort(v.begin(),v.end(),cmp);

    for(auto &i : v)    cout << get<2>(i);
}
