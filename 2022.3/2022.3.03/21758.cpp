//난이도 : 실버1, 유형 : 그리디

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

int Ldp[100001],Rdp[1000010];

void print(int n){
    for(int i=1;i<=n;i++)
        cout << Ldp[i] << " ";
    cout << "\n";
    for(int i=1;i<=n;i++)
        cout << Rdp[i] << " ";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,ans = -1;

    cin >> n;

    vector<int> v(n+2);

    for(int i=1;i<=n;i++){
        cin >> v[i];
        Ldp[i] = Ldp[i-1] + v[i];
    }
    for(int i=n;i>=1;i--)
        Rdp[i] = Rdp[i+1] + v[i];

 //   print(n);

    //벌벌통
    for(int i=2;i<n;i++) {
        ans = max(ans, (Ldp[n] - Ldp[1]) + (Ldp[n] - Ldp[i] - v[i]));
    }

    //통벌벌
    for(int i=n-1;i>1;i--){
        ans = max(ans,(Rdp[1] - Rdp[n]) + (Rdp[1] - Rdp[i] - v[i]));
    }

    //벌통벌
    for(int i=2;i<n;i++){
        ans = max(ans,(Ldp[i] - Ldp[1]) + (Rdp[i] - v[n]));
    }

    cout << ans;
}
