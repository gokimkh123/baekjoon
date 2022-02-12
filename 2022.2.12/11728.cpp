//난이도 : 실버 5, 유형 : 정렬(병합)

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

    int n,m,dex1 = 0,dex2 = 0;
    cin >> n >> m;

    vector<int> a(n+1,1000000001);
    vector<int> b(m+1,1000000001);
    vector<int> ans;

    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<m;i++)
        cin >> b[i];

    for(int i=0;i<n+m;i++){
        if(a[dex1] >= b[dex2]) ans.push_back(b[dex2++]);
        else if(a[dex1] <= b[dex2]) ans.push_back(a[dex1++]);
    }



    for(auto &i : ans)
        cout << i << " ";
}

