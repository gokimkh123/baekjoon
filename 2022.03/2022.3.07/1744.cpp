//난이도 : 골드4, 유형 : 그리디, 정렬

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

vector<int> L;
vector<int> R;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,ans = 0;
    cin >> n;

    for(int i=0;i<n;i++){
        int a;cin >> a;

        if(a <= 0) L.push_back(a);
        else R.push_back(a);
    }
    sort(L.begin(),L.end());
    sort(R.begin(),R.end());

    if(!L.empty()){
        for(int i=0;i<L.size()-1;i+=2){
            if((L[i] + L[i+1]) >= (L[i] * L[i+1])) ans += L[i] + L[i+1];
            else ans += (L[i] * L[i+1]);
        }
    }
    if(!R.empty()){
        for(int i=R.size()-1;i>=1;i-=2){
            if((R[i] + R[i-1]) >= (R[i] * R[i-1])) ans += R[i] + R[i-1];
            else ans += (R[i] * R[i-1]);
        }
    }

    if(L.size() % 2 == 1) ans += L[L.size()-1];
    if(R.size() % 2 == 1) ans += R[0];

    cout << ans;
}


