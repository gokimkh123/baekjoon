//난이도 : 실버2, 유형 : 분할정복

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define mod
using namespace std;

int n,arr[1025][1025],ans = -10001;
vector<int> v;

int solve(int y, int x){
    vector<int> temp;
    for(int i=y;i<y+2;i++){
        for(int j=x;j<x+2;j++)
            temp.push_back(arr[i][j]);
    }

    sort(temp.begin(),temp.end());

    return temp[2];

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin >> arr[i][j];
    }


    while(n > 1){
        for(int i=0;i<n;i+=2){
            for(int j=0;j<n;j+=2){
                arr[i/2][j/2] = solve(i,j);
            }
        }
        n /= 2;
    }

    cout << arr[0][0];
}
