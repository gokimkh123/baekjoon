//난이도 : 실버5, 유형 : 그리디

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

    l s;cin >> s;

    l sum = 0;
    for(l i=1;i<=s;i++){
        sum += i;
        if(sum > s){
            cout << i-1;
            return 0;
        }
        else if(sum == s){
            cout << i;
            return 0;
        }
    }
    cout << sum;
}

