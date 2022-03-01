//난이도 : 실버2, 유형 : 재귀함수

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define mod
using namespace std;

l solve(l k){
    if(k == 0) return 0;
    if(k % 2) return 1-solve((k-1)/2);
    else return solve(k/2);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    l k;
    cin >> k;

    cout << solve(k-1);
}
