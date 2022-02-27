//난이도 : 실버3, 유형 : 문자열

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
#define mod
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<string> v;
    int t;cin >> t;

    while(t--) {

        string temp = "";
        string s;cin >> s;

        bool check = false;

        for (int i = 0; i < s.size(); i++) {
            if (check) temp += s[i];
            if (s[i] == '.') check = true;
        }

        v.push_back(temp);
    }

    sort(v.begin(),v.end());
/*
    for(int i=0;i<v.size();i++)
        cout << v[i] << " ";
    cout << "\n";
*/
    int cnt = 1;
    for(int i=1;i<v.size();i++){
        if(v[i-1] != v[i]) {
            cout << v[i-1] << " " << cnt << "\n";
            cnt = 0;
        }
        cnt++;
    }
    cout << v[v.size()-1] << " " << cnt;
}
