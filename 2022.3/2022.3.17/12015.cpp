//난이도 : 골드2, 유형 : 이분탐색

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


    int n,ans = 0,temp;
    cin >> n;
    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin >> temp;

        if(temp > v.back()){
            v.push_back(temp);
            ans++;
        }
        else{
            auto idx = lower_bound(v.begin(),v.end(),temp);
            *idx = temp;
        }
    }

    cout << ans;
}

