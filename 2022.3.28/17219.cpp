//난이도 : 실버4, 유형 : map

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<p>
#define F first
#define S second
using namespace std;

unordered_map<string,string> arr;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    string a,b;

    cin >> n >> m;

    while(n--){
        cin >> a >> b;

        arr[a] = b;
    }

    while(m--){
        cin >> a;

        cout << arr[a] << "\n";
    }
}


