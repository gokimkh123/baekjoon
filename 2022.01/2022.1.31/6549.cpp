// 난이도 : 플레5 , 유형 : 분할정복

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

vector<long long> v;

long long f(long long left,long long right){
    if(left == right)  return v[left];

    long long int mid = (left + right) / 2;

    long long int ret = max(f(left,mid),f(mid+1,right));

    long long lo = mid, hi = mid + 1;
    long long height = min(v[lo],v[hi]);
    ret = max(ret,height * 2);

    while(left < lo || hi < right){
        if(hi < right && (lo == left || v[lo-1] < v[hi+1])){
            hi++;
            height = min(height,v[hi]);
        }
        else{
            lo--;
            height = min(height,v[lo]);
        }
        ret = max(ret, height * (hi - lo +1));
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    while(1){
        long long int n;cin >> n;
        if(!n) return 0;

        for(int i=0;i<n;i++){
            int a;cin >> a; v.push_back(a);
        }

        cout << f(0,n-1) << "\n";

        for(int i=0;i<n;i++)
            v.pop_back();

    }
}
