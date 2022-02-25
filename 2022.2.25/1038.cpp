//난이도 : 골드5, 유형 : 백트래킹

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

l n,arr[11],Size,cnt = -1;
bool check[11],End;

void back(int num){
    if(End) return;

    if(num == Size){
        bool ok = true;

        for(int i=0;i<num-1;i++){
            if(arr[i] < arr[i+1]){
                ok = false;
                break;
            }
        }

        if(ok){
            ++cnt;
            if(cnt == n){
                for(int i=0;i<num;i++){
                    cout << arr[i];
                }
                End = true;
            }
        }
        return;
    }


    for(int i=0;i<=9;i++){
        if(check[i]) continue;
        arr[num] = i;check[i] = true;
        back(num+1);
        arr[num] = 0;check[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;

    for(int i=1;i<=10;i++){
        Size = i;
        back(0);
    }

    if(!End) cout << "-1";
}

