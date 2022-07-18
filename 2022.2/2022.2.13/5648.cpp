//난이도 : 실버4, 유형 : 정렬, stoll(문자열 -> 정수변환)

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

l re(string a){
    reverse(a.begin(),a.end());
    return stoll(a);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<l> v;

    l  n;cin >> n;

    while(n--){
        string a;cin >> a;

        v.push_back(re(a));
    }

    sort(v.begin(),v.end());

    for(auto &i : v) cout << i << "\n";

}

