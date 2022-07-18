//난이도 : 실버 4, 유형 : 정렬

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
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<string> v;

    string s;cin >> s;

    for(int i=0;i<s.size();i++){
        string save = "";
        for(int j=i;j<s.size();j++) save += s[j];
        v.push_back(save);
    }

    sort(v.begin(),v.end());

    for(auto &i : v)
        cout << i << "\n";
}

