//난이도 : 실버2, 유형 : 순열

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

    int n,ans = -10000;cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];

    sort(v.begin(),v.end());
    do{
        int sum = 0;
        for(int i=0;i<n-1;i++)
            sum += (abs(v[i] - v[i+1]));
        ans = max(ans,sum);

    }while(next_permutation(v.begin(),v.end()));

    cout << ans;
}

