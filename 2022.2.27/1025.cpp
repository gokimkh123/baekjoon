//난이도 : 골드5, 유형 : 완전탐색

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

int n,m,arr[10][10];

bool check(int num){
    int sq = sqrt(num);

    if(sq * sq == num) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int ans = -1;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        string s;cin >> s;
        for(int j=0;j<m;j++)
            arr[i][j+1] = s[j] - 48;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int di=-n;di<n;di++){
                for(int dj=-m;dj<m;dj++){
                    if(!di && !dj) continue;

                    int y = i, x = j,temp = 0;
                    while(y >= 1 && y <= n && x >= 1 && x <= m){
                        temp *= 10;
                        temp += arr[y][x];

                        if(check(temp)) ans = max(ans,temp);

                        y += di;
                        x += dj;
                    }
                }
            }
        }
    }

    cout << ans;
}
