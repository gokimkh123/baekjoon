//난이도 : 골드2, 유형 : 이분탐색, 파라미터 서치

#include <iostream>
#include <vector>
#include <cmath>
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
#define mod
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    l n,k;

    cin >> n >> k;

    l st = 1, en = k;

    while(en - st > 0){
        l mid = (st + en) / 2,cnt = 0;
        for(l i=1;i<=n;i++)
            cnt += min(n,mid / i);

        if(cnt >= k) en = mid;
        else st = mid + 1;
    }
    cout << st;
}
