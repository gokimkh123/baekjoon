#include <iostream>
#include <vector>
using namespace std;

vector<int> d;vector<int> w;
int n,MAX = -1,cnt;

void solve(int i){
    if(i == n){
        MAX = max(cnt, MAX);
        return;
    }

    if(d[i] <= 0 || cnt == n-1){
        solve(i+1);
        return;
    }

    for(int k=0;k<n;k++){
        if(k == i || d[k] <= 0 ) continue;

        d[i] -= w[k];d[k] -= w[i];

        if(d[i] <= 0) cnt++;
        if(d[k] <= 0) cnt++;

        solve(i+1);

        if(d[i] <= 0) cnt--;
        if(d[k] <= 0) cnt--;
        d[i] += w[k];d[k] += w[i];
    }


}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;

    for(int i=0;i<n;i++){
        int a,b;cin >> a >> b;d.push_back(a);w.push_back(b);
    }

    solve(0);

    cout << MAX;
}
