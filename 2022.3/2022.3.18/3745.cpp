//난이도 : 골드2, 유형 : 이분탐색

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


    int n;
    while(cin >> n){
        int temp,ans = 0;
        vector<int> v(n);

        for(int i=0;i<n;i++){
            cin >> temp;

            if(temp > v.back()){
                v.push_back(temp);
                ans++;
            }
            else{
                auto it = lower_bound(v.begin(),v.end(),temp);
                *it = temp;
            }
        }

        cout << ans << "\n";
    }
}

