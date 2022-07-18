// 난이도 : 실버 3, 유형 : 구현

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#define l long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    long long n,ans = 0;cin >> n;

    for (int i = 1; i <= n; i *= 10)   ans += n - i + 1;
    cout << ans;
}

/*
 1-9 1개 n-1+1
 10-99 2개 n-10+1
 100-999 3개 n-100+1
 1000-9999 4개 n-1000+1

 */
