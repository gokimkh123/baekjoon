//난이도 : 실버2, 유형 : 우선순위 큐(매번 정렬하는 대신 이거쓰면 좋다.), 그리디

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
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    priority_queue<l,vector<l>,greater<l>> q;

    l n,m;cin >> n >> m;
    vector<l> v(n);

    for(int i=0;i<n;i++)
        cin >> v[i];

    for(auto &i : v)
        q.push(i);

    while(m--){
        l x = q.top();q.pop();
        l y = q.top();q.pop();
        q.push(x+y);q.push(x+y);
    }
    l sum = 0;
    while(!q.empty()){
        sum += q.top();q.pop();
    }

    cout << sum;
}

