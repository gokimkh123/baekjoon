//난이도 : 실버 4, 유형 : 정렬, 구조체

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
    int math,en,kor;
    string name;
};
list a[100001];

bool cmp(const list &u,const list &v){
    if(u.kor > v.kor) return true;
    else if(u.kor == v.kor){
        if(u.en < v.en) return true;
        else if(u.en == v.en) {
            if(u.math > v.math) return true;
            else if(u.math == v.math) return u.name < v.name;
            return false;
        }
        return false;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;cin >> n;

    for(int i=0;i<n;i++){
        cin >> a[i].name >> a[i].kor >> a[i].en >> a[i].math;
    }


    sort(a,a+n,cmp);

    for(int i=0;i<n;i++){
        cout << a[i].name << "\n";
    }
}

