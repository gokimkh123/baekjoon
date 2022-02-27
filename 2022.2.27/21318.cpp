//난이도 : 실버1, 유형 : 누적합

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

l arr[100000],dp[100000],check[100000];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    l n,q,x,y;
    cin >> n;

    for(int i=1;i<=n;i++)
        cin >> arr[i];


    for(int i=1;i<n;i++){
        if(arr[i] > arr[i+1]) check[i] = 1;
        else check[i] = 0;
    }
    check[n] = 0;

    for(int i=1;i<=n;i++)
        dp[i] = dp[i-1] + check[i];

    cin >> q;

    while(q--){
        cin >> x >> y;

        if(check[y] != 0 ) cout << dp[y] - 1 - dp[x-1] << "\n";
        else cout << dp[y] - dp[x-1] << "\n";
    }
}
