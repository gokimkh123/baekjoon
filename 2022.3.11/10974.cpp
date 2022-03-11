//난이도 : 실버3, 유형 : 백트래킹

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;cin >> n;

    vector<int> v;

    for(int i=1;i<=n;i++)
        v.push_back(i);

    do{
        for(auto &i : v)
            cout << i << " ";
        cout << "\n";

    }while(next_permutation(v.begin(),v.end()));

}


