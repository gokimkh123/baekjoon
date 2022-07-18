//난이도 : 실버2, 유형 : 그리디

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
#define p pair<int,int>
using namespace std;

p arr[100001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;cin >> n;

    for(int i=0;i<n;i++)
        cin >> arr[i].second >> arr[i].first;


    sort(arr,arr+n);

    int time = 0,ans = 0;

    for(int i=0;i<n;i++){
        if(time > arr[i].second) continue;

        ans++;
        time = arr[i].first;
    }

    cout << ans;

}

