//난이도 : 골드5, 유형 : 이분탐색, 파라미터 서치

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,C,ans = 0;

    cin >> n >> C;

    vector<int> v(n);

    for(int i=0;i<n;i++)
        cin >> v[i];

    sort(v.begin(),v.end());

    int st = 1, en = v[n-1] - v[0];

    while(en - st >= 0){
        int mid = (st + en) / 2,start = v[0], cnt = 1;

        for(int i=1;i<n;i++){
            int d = v[i] - start;

            if(d >= mid){
                cnt++;
                start = v[i];
            }
        }

        if(cnt >= C){
            st = mid + 1;
            ans = max(ans,mid);
        }
        else en = mid - 1;
    }
    cout << ans;
}

