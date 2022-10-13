// 난이도 : 실버 2, 유형 : 완전탐색, 백트래킹,시뮬레이션

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#define l long long
#define INF 2e9
using namespace std;

int arr[21][21],n;
vector<int> v;
vector<int> idx;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;

    for(int i=0;i<n;i++){
        v.push_back(i);
        idx.push_back(i < n/2 ? 0 : 1);
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;cin >> a;
            if(a) arr[i][j] = a;
        }
    }
    int ans = INF;
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

       ans = min(ans,abs(sum1-sum2));

    }while(next_permutation(idx.begin(),idx.end()));

    cout << ans;
}


/*

 이해 : 1~n번까지 팀을 모두 속하게 하되(팀은 총 n/2팀) 각팀의 능력치 최소화하기

 1. 0이면 ii 값이다
 2. 이차원 배열을 만들어서 arr[i][j],arr[j][i] 그래프를 만들기
 3. 백트래킹을 이용하며 모든 경우의 수 탐색
    n = 4일때 (1,2),(3,4)         1234,1324,1423
             (1,3),(2,4)
             (1,4),(2,3)
 4. 이중반복문으로 차이 완전탐색
 */
