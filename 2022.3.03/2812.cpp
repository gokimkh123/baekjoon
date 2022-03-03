//난이도 : 골드4, 유형 : 자료구조, 그리디

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define MAX 1000000000
using namespace std;

deque<char> dq;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    int n,k;

    cin >> n >> k;

    cin >> s;

    for(int i=0;i<n;i++){
        while(k && !dq.empty() && s[i] > dq.back()){
            dq.pop_back();
            k--;
        }
        dq.push_back(s[i]);
    }

    for(int i=0;i<dq.size()-k;i++)
        cout << dq[i];
}
