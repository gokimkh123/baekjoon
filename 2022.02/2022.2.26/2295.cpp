//난이도 : 골드4, 유형 : 이분탐색

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
#define mod
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<int> sum;
    vector<int> num;

    int n;cin >> n;

    for(int i=0;i<n;i++){
        int a;cin >> a;num.push_back(a);
    }

    sort(num.begin(),num.end());

    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            sum.push_back(num[i]+num[j]);

    sort(sum.begin(),sum.end());

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(binary_search(sum.begin(),sum.end(),num[i] - num[j])){
                cout << num[i];
                return 0;
            }
        }
    }
}

