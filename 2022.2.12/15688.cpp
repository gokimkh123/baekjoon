//난이도 : 실버 5,유형 : 정렬(std::sort사용, 퀵소트 구현시O(n^2) 때문에 시간초과, 병합정렬로 O(nlon)으로 통과

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

    vector<int> arr;
    int n;cin >> n;

    for(int i=0;i<n;i++){
        int a;cin >> a; arr.push_back(a);
    }

    sort(arr.begin(),arr.end());

    for(auto &i : arr)
        cout << i << "\n";
}
)
