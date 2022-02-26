//난이도 : 실버3, 유형 : 이분탐색, 파라미터 서치

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

    l m,ans = -1;
    int n;cin >> n;

    vector<l> v;

    for(int i=0;i<n;i++){
        int a;cin >> a;v.push_back(a);
    }

    cin >> m;

    sort(v.begin(),v.end());

    l st = 0,en = v[n-1];

    while(en - st >= 0){
        l mid = (st + en) /  2;
        l sum = 0;

        for(auto &i : v){
            if(i > mid) sum += mid;
            else sum += i;
        }

        if(sum <= m){
            ans = max(ans,mid);
            st = mid + 1;
        }
        else en = mid - 1;
    }

    cout << ans;
}

