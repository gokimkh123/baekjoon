//난이도 : 실버4, 유형 : 누적합

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<l>
using namespace std;

int main(){
   ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

   l m,a,x,sum = 0,XORSum = 0;

   cin >> m;

   for(int i=0;i<m;i++){
       cin >> a;
       if(a == 1){
           cin >> x;
           sum += x;
           XORSum ^= x;
       }
       else if(a == 2){
           cin >> x;
           sum -= x;
           XORSum ^= x;
       }
       else if(a == 3) cout << sum << "\n";
       else if(a == 4) cout << XORSum << "\n";

   }
}
