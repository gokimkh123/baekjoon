//난이도 : 골드5, 유형 : 재귀, 자료구조

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define mod
using namespace std;

string s;
stack<int> st;
vector<p> v;
vector<string> ans;
bool check[201];

void back(int cnt,int num){
    if(cnt == 0){
        string temp = "";

        for(int i=0;i<s.size();i++){
            if(!check[i]) temp += s[i];
        }
        ans.push_back(temp);
        return;
    }

    for(int i=num;i<v.size();i++){
        check[v[i].first] = check[v[i].second] = true;
        back(cnt - 1, i + 1);
        check[v[i].first] = check[v[i].second] = false;
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> s;

    for(int i=0;i<s.size();i++){
        if(s[i] == '(') st.push(i);
        if(s[i] == ')') {
            v.push_back({st.top(),i});
            st.pop();
        }
    }

    for(int i=1;i<=v.size();i++){
        back(i,0);
    }
    sort(ans.begin(),ans.end());

    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << "\n";
}
