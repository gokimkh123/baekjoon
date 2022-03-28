//난이도 : 실버5, 유형 : 구현

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<p>
#define F first
#define S second
using namespace std;

bool arr[21];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int m,x;
    string s;

    cin >> m;

    while(m--){
        cin >> s;

        if(s == "all" || s == "empty"){
            if(s == "all") memset(arr,true,sizeof(arr));
            else if(s == "empty") memset(arr,false,sizeof(arr));
        }
        else{
            cin >> x;
            if(s == "add" && !arr[x]) arr[x] = true;
            else if(s == "remove" && arr[x]) arr[x] = false;
            else if(s == "check") cout << arr[x] << "\n";
            else if(s == "toggle"){
                if(arr[x]) arr[x] = false;
                else arr[x] = true;
            }
        }
    }
}

