//난이도 : 실버4, 유형 : 수학

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
   l n;cin >> n;

   l temp = sqrt(n);

   if(temp*temp < n) cout << temp + 1;
   else cout << temp;

}

