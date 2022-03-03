//난이도 : 실버4, 유형 : 문자열, map

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define mod
using namespace std;

unordered_map<string,int> M;
vector<string> v;
vector<pair<string,int>> temp;

bool cmp(const pair<string,int> &a,const pair<string,int> &b){
    if(a.second < b.second) return true;
    else if(a.second == b.second){
        if(a.first > b.first) return true;
        else return false;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;cin >> n;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        M[s]++;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    for(int i=0;i<v.size();i++)
        temp.push_back({v[i],M[v[i]]});


    sort(temp.begin(),temp.end(),cmp);

    cout << temp[temp.size()-1].first;
}
