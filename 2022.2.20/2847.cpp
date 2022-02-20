//난이도 : 실버4, 유형 : 그리디

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
#define p pair<int,int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,ans = 0;cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];

    for(int i=n-2;i>=0;i--){
        if(v[i+1] <= v[i]){
            ans += (v[i]-v[i+1] + 1);
            v[i] -= (v[i]-v[i+1] + 1);
        }
    }

    cout << ans;
}

