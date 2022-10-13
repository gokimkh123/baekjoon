//난이도 : 골드5, 유형 : 구현

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

int arr[502][502],H,W;

void print(int x,int y){
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

int check(int x,int y){
    for(int i=y+1;i<W;i++)
        if(arr[x][i] == 1) return i;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int ans = 0;

    cin >> H >> W;

    for(int i=0;i<W;i++){
        int a;cin >> a;
        for(int j=0;j<a;j++)
            arr[j][i] = 1;
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(arr[i][j] == 2) continue;
            if(arr[i][j] == 1){
                if(arr[i][j] == arr[i][j+1])  continue;
                int idx = check(i,j);
                if(idx != -1){
                    for(int x=j+1;x<idx;x++)
                        arr[i][x] = 2;
                }
            }
        }
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++)
            ans += arr[i][j] == 2;
    }

    //print(H,W);
    cout << ans;
}

