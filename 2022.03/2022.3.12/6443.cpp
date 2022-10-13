//난이도 : 골드5, 유형 : 백트래킹

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;

    cin >> n;

    for(int i=0;i<n;i++){
        vector<string> ans;
        string s;
        cin >> s;

        sort(s.begin(),s.end());

        do{
            ans.push_back(s);
        }while(next_permutation(s.begin(),s.end()));

        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        for(auto &j : ans)
            cout << j << "\n";
    }
}

