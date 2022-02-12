//난이도 : 브론즈 1, 유형 : 정렬(퀵정렬 사용)

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

void quicksort(int st,int en){
    if(en <= st+1) return;

    int pivot = arr[st];
    int L = st + 1, R = en-1;

    while(1){
        while(L <= R && arr[L] <= pivot) L++;
        while(L <= R && arr[R] >= pivot) R--;
        if(L > R) break;
        swap(arr[L],arr[R]);
    }
    swap(arr[st],arr[R]);
    quicksort(st,R);
    quicksort(R+1,en);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;cin >> n;

    for(int i=0;i<n;i++) cin >> arr[i];

    quicksort(0,n);

    for(int i=0;i<n;i++) cout << arr[i] << "\n";
}

