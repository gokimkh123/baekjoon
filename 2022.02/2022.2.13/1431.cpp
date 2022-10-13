//난이도 : 실버3, 유형 : 정렬, 구조체

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

struct list{
    int sum;
    string s;
    int size;
};
list a[52];

bool cmp(const list &u,const list &v){
    if(u.size < v.size) return true;
    else if(u.size == v.size){
        if(u.sum < v.sum) return true;
        else if(u.sum == v.sum){
            if(u.s < v.s) return true;
            else return false;
        }
        return false;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;cin >> n;

    for(int i=0;i<n;i++){
        cin >> a[i].s;

        a[i].size = a[i].s.size();

        for(int j=0;j<a[i].size;j++){
            if(int(a[i].s[j]) < 65 || int(a[i].s[j]) > 90) a[i].sum += (a[i].s[j] - 48);
        }
    }


    sort(a,a+n,cmp);

    for(int i=0;i<n;i++){
        cout << a[i].s << "\n";
    }
}

