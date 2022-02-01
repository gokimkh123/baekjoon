// 난이도: 실버5, 유형: 정렬

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

   int k;cin >> k;

   for(int x=0;x<k;x++){
       int n,MAX = -1;cin >> n;
       vector<int> v;

       for(int i=0;i<n;i++){
           int a;cin >> a;v.push_back(a);
       }
       sort(v.begin(),v.end());

       for(int i=0;i<n-1;i++){
           MAX = max(MAX,v[i+1] - v[i]);
       }

       cout << "Class " << x+1 << "\n";
       cout << "Max " << v[n-1] << ", " << "Min " << v[0] << ", Largest gap " << MAX << "\n";

   }
}

