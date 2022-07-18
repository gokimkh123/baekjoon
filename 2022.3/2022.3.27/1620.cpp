//난이도 : 실버4, 유형 : map

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<int>
#define F first
#define S second
using namespace std;

unordered_map<string,int> arr;
unordered_map<string ,string> arr1;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    string s,idx;

    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> s;

        arr[s] = i;
        arr1[to_string(i)] = s;
    }

    while(m--){
        bool check = false;
        cin >> idx;

        for(auto &i : idx){
            if('A' <= i && i <= 'z'){
                check = true;
                break;
            }
        }

        if(!check) cout << arr1[idx] << "\n";
        else cout << arr[idx] << "\n";
    }
}

