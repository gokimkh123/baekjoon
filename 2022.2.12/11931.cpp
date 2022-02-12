// 난이도 : 실버 5, 유형 : 정렬(병합정렬 사용, 퀵소트를 구현하니 최악의 경우 n^2이 나와 시간초과)

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <deque>
#define l long long
#define INF 2e9
using namespace std;

int arr[1000001];
int temp[1000001];

void Merge(int st,int en){
    int mid = (st+en) / 2;

    int sidx = st, midx = mid;

    for(int i=st;i<en;i++){
        if(midx == en) temp[i] = arr[sidx++];
        else if(sidx == mid) temp[i] = arr[midx++];
        else if(arr[sidx] <= arr[midx]) temp[i] = arr[sidx++];
        else temp[i] = arr[midx++];
    }
    for(int i=st;i<en;i++) arr[i] = temp[i];
}

void mergsort(int st,int en){
    if(en-st == 1) return;

    int mid = (st + en) / 2;
    mergsort(st,mid);
    mergsort(mid,en);
    Merge(st,en);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;cin >> n;

    for(int i=0;i<n;i++) cin >> arr[i];

    mergsort(0,n);

    for(int i=n-1;i>=0;i--) cout << arr[i] << "\n";
}

