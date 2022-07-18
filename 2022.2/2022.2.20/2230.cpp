//난이도 : 골드5, 유형 : 투포인터

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

    int n,m;

    cin >> n >> m;
    vector<l> v(n);
    for(int i=0;i<n;i++)    cin >> v[i];

    l start = 0,end = 0,ans = 10000000001;

    sort(v.begin(),v.end());

    while(end - start >= 0 && end < n){
        l st = v[end] - v[start];
        if(st >= m){
            ans = min(ans,st);
            start++;
        }
        else end++;
    }

    cout << ans;
}

