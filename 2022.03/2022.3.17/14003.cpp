//난이도 : 플레5, 유형 : 경로추적, 이분탐색

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

int cnt[1000001],num[1000001];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


    int n;
    cin >> n;

    vector<int> v;
    vector<int> temp;

    for(int i=0;i<n;i++){
        cin >> num[i];

        if(i == 0 || num[i] > v.back()){
            v.push_back(num[i]);
            cnt[i] = v.size();
        }
        else{
            auto idx = lower_bound(v.begin(),v.end(),num[i]);
            *idx = num[i];
            int a = idx - v.begin();
            cnt[i] = a + 1;
        }
    }

    int ans = v.size();

    cout << ans << "\n";

   for(int i=n-1;i>=0;i--){
       if(ans == 0) break;

       if(cnt[i] == ans){
           temp.push_back(num[i]);
           ans--;
       }
   }

   for(int i=temp.size()-1;i>=0;i--)
       cout << temp[i] << " ";

}

