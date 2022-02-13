//난이도 : 실버4, 유형 : 정렬

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <deque>
#define l long long
#define INF 2e9
using namespace std;

vector<l> v;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    l ans = -1,cnt = 1,temp = -1;

    int n;cin >> n;

    for(int i=0;i<n;i++){
        l a;cin >> a;v.push_back(a);
    }
    sort(v.begin(),v.end());

    ans = v[0];

    for(int i=0;i<n-1;i++){
        if(v[i] != v[i+1]){

            if(cnt > temp){
                temp = cnt;
                ans = v[i];
            }
            cnt = 1;
            continue;
        }
        else cnt++;
    }

    if(cnt > temp) ans = v[n-1];
    cout << ans;
}

