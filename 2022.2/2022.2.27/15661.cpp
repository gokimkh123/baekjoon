//난이도 : 실버1, 유형 : 백트래킹, 완전탐색


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

int arr[21][21],n;

int Search(int num){
    int temp = INF;
    vector<int> idx;
    vector<int> v;

    for(int i=0;i<n;i++){
        idx.push_back(i < num ? 0 : 1);
        v.push_back(i);
    }

    do{
        int sum1 = 0,sum2 = 0;

        for(int i=0;i<n;i++){
            if(idx[i]) continue;
            for(int j=i+1;j<n;j++){
                if(idx[j]) continue;
                sum1 += arr[v[i]][v[j]] + arr[v[j]][v[i]];
            }
        }

        for(int i=0;i<n;i++){
            if(!idx[i]) continue;
            for(int j=i+1;j<n;j++){
                if(!idx[j]) continue;
                sum2 += arr[v[i]][v[j]] + arr[v[j]][v[i]];
            }
        }

        temp = min(temp,abs(sum1-sum2));

    }while(next_permutation(idx.begin(),idx.end()));

    return temp;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int ans = INF;
    cin >> n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> arr[i][j];

    for(int i=2;i<n-1;i++)
        ans = min(ans,Search(i));


    cout << ans;
}
