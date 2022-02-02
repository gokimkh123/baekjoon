// 난이도 : 플레 5, 유형 : 분할정복


#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#define l long long
using namespace std;

vector<l> v;

l f(l left, l right){
    if(left == right) return v[left];

    l mid = (left + right) / 2;

    l ret = max(f(left,mid),f(mid+1,right));

    l lo = mid, ro = mid+1;
    l height = min(v[lo],v[ro]);
    ret = max(ret,height * 2);

    while(left < lo || ro < right){
        if(ro < right && (left == lo || v[lo - 1] < v[ro + 1])){
            ro++;
            height = min(height,v[ro]);
        }
        else {
            lo--;
            height = min(height,v[lo]);
        }
        ret = max(ret, (height * (ro-lo+1)));
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;

    cin >> n;

    for(int i=0;i<n;i++){
        int a;cin >> a;v.push_back(a);
    }

    cout << f(0,n-1);
}
