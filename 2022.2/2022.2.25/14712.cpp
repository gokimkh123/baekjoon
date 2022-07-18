//난이도 : 실버1, 유형 : 백트래킹

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

int n,m,arr[26][26],ans;

void back(int num){
    if(num == n*m){
        ans++;
        return;
    }
    int y = num / m + 1, x = num % m + 1;

    if(arr[y][x-1] && arr[y-1][x-1] && arr[y-1][x]) back(num+1); // 2*2될경우
    else {
        arr[y][x] = 1;
        back(num+1);        // 선택한 경우
        arr[y][x] = 0;
        back(num+1);        // 선택하지 않은경우
    }

}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;

    back(0);

    cout << ans;
}

