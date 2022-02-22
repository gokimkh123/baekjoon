//난이도 : 실버2, 유형 : 그리디

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
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;cin >> t;

    while(t--){
        l ans = 0,MAX = 0;
        int n;cin >> n;
        vector<l> v(n);

        for(int i=0;i<n;i++)
            cin >> v[i];

        for(int i=n-1;i>=0;i--){
            MAX = max(MAX,v[i]);

            if(v[i] < MAX) ans += (MAX - v[i]);
        }
        cout << ans << "\n";
    }
}

