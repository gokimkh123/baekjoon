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

int arr[1025][1025],dp[1025][1025];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,m;

    cin >> n >> m;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> arr[i][j];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            dp[i][j] = dp[i][j-1] + arr[i][j];
    }

    while(m--){
        int x1,y1,x2,y2,sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int i=x1;i<=x2;i++)
            sum += (dp[i][y2] - dp[i][y1-1]);

        cout << sum << "\n";
    }
}
