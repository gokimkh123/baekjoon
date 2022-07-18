//난이도 : 플레5, 유형 : 그리디, 문자열, 정렬

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef tuple<int,int,int> tu;
typedef vector<int> vc;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    vector<string> v;

    int n;

    string s;

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(),v.end(),[](string a,string b){
        return a + b > b + a;
    });

    if(v[0][0] == '0') cout << "0";
    else{
        for(auto &i : v)
            cout << i;
    }
}

