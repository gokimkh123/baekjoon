//난이도 : 실버3, 유형 : 자료구조(덱)

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define mod
using namespace std;
deque<p> dq;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int a;cin >> a;
        dq.push_back({a,i+1});
    }

    while(!dq.empty()){
        int ans = dq.front().second;
        int temp = dq.front().first;dq.pop_front();

        if(temp > 0){
            for(int i=0;i<temp-1;i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
            cout << ans << " ";
        }
        else if(temp < 0){
            for(int i=0;i<abs(temp);i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cout << ans << " ";
        }
    }
}
