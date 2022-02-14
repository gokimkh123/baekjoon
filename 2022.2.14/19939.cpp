//난이도 : 실버5, 유형 : 수학

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

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<int> v;
    int sum = 0;
    int n,k;cin >> n >> k;

    for(int i=1;i<=k;i++) sum += i;

    n -= sum;

    if(n < 0) cout << "-1";
    else{
       if(n % k == 0) cout << k-1;
       else cout << k;
    }

}

