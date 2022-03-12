//난이도 : 골드5, 유형 : 백트래킹

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

int arr[12][12],ans;
bool check[12];
void back(int num,int sum){
    if(num == 11){
        ans = max(sum,ans);
        return;
    }

    for(int i=0;i<11;i++){
        if(!check[i] && arr[num][i]){
            check[i] = true;sum += arr[num][i];
            back(num+1,sum);
            sum -= arr[num][i];check[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int C;cin >> C;

    while(C--){
        ans = 0;

        for(int i=0;i<11;i++){
            for(int j=0;j<11;j++)
                cin >> arr[i][j];
        }
        back(0,0);
        cout << ans << "\n";
    }

}

