//난이도 : 골드4 , 유형 : 투포인터

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;cin >> n;
    vector<l> v(n);

    long long MIN = 3000000000 + 1,a,b,c;

    for(auto &i : v) cin >> i;

    sort(v.begin(),v.end());

    for(int i=0;i<n-2;i++){
        int st = i+1, en = n-1;

        while(en - st > 0){
            l sum = v[st] + v[en] + v[i];

            if(MIN > llabs(sum)){
                MIN = llabs(sum);
                a = v[i],b = v[st], c = v[en];
            }
            if(sum < 0) st++;
            else en--;
        }

    }
    cout << a << " " << b << " " << c;

}

