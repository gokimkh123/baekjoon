//난이도 : 실버3, 유형 : 수학, map

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<p>
#define F first
#define S second
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t,n;
    cin >> t;

    while(t--){
        int ans = 1;
        string a,b;
        cin >> n;
        unordered_map<string,int> arr;

        for(int i=0;i<n;i++){
            cin >> a >> b;
            arr[b]++;
        }

        for(auto &i : arr)
            ans *= (i.second + 1);
        cout << ans - 1 << "\n";
    }
}

