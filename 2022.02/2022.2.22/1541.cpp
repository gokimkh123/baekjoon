//난이도 : 실버2, 유형 : 그리디, 수학(분배법칙사용)

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
using namespace std;

int temp,ans;
int change = 1;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    string s;cin >> s;

    for(auto &i : s){
        if(i == '+' || i == '-'){
            ans += temp * change;
            if(i == '-') change = -1;
            temp = 0;
        }
        else{
            temp *= 10;
            temp += i - '0';
        }
    }

    cout << ans + temp * change;

}

