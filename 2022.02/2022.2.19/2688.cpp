//난이도 : 골드5, 유형 : dp

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

l dp[100][100];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

   int t;cin >> t;


   for(int i=0;i<=9;i++)
       dp[1][i] = 1;

   for(int i=2;i<=64;i++){
       for(int j=0;j<=9;j++){
           for(int k=0;k<=j;k++)
               dp[i][j] += dp[i-1][k];
       }
   }

   while(t--){
       l ans = 0;
       int n;cin >> n;

       for(int i=0;i<=9;i++)
           ans += dp[n][i];

       cout << ans << "\n";
   }
}

