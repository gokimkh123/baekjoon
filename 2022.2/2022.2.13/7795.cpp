//난이도 : 실버3, 유형 : 이분탐색 lower_bound

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


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;cin >> t;

    while(t--){
        vector<int> a;
        vector<int> b;
        int cnt = 0;
        int n,m;cin >> n >> m;

        for(int i=0;i<n;i++){
            int x;cin >> x;a.push_back(x);
        }

        for(int i=0;i<m;i++){
            int x;cin >> x;b.push_back(x);
        }

       sort(a.begin(),a.end());
       sort(b.begin(),b.end());

       for(int i=0;i<n;i++){
           cnt += (lower_bound(b.begin(),b.end(),a[i]) - b.begin());
       }
       cout << cnt << "\n";
    }
}

