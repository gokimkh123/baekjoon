// 난이도 : 실버 4, 유형 : binary_search(map을 이용해 구현 가능)

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#define l long long
using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;

    cin >> n;

    for(int i=0;i<n;i++){
        int a;cin >> a;v.push_back(a);
    }
    cin >> m;

    sort(v.begin(),v.end());

    for(int i=0;i<m;i++){
        int a;cin >> a;

        cout << binary_search(v.begin(),v.end(),a)  << " ";
    }
}
