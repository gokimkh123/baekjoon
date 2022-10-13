//난이도 : 실버4, 유형 : 문자열

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

    int t;cin >> t;

    while(t--){
        bool check = false;

        string s;cin >> s;

        if(s[0] >= 'G' || s[s.size()-1] >= 'G') check= true;
        else{
            for(int i=1;i<s.size();i++){
                if(s[i-1] == s[i]) continue;

                if(s[i-1] == 'A' && s[i] != 'F'){
                    check = true;
                    break;
                }
                if(s[i-1] == 'F' && s[i] != 'C'){
                    check = true;
                    break;
                }
            }
        }

        if(check) cout << "Good\n";
        else cout << "Infected!\n";
    }
}
