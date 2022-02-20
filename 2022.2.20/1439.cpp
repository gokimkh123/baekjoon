//난이도 : 실버5, 유형 : 그리디, 자료구조

#include <iostream>
#include <vector>
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

queue<char> q;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    int one = 0,zero = 0,ans = 0;
    string s;cin >> s;

    for(int i=0;i<s.size();i++)
        q.push(s[i]);

    while(!q.empty()){

        if(q.front() == '0'){
            while(1){
                if(q.empty() || q.front() == '1') break;
                q.pop();
            }
            zero++;
        }

        else if(q.front() == '1'){
            while(1){
                if(q.empty() || q.front() == '0') break;
                q.pop();
            }
            one++;
        }
    }
    ans = min(zero,one);

    cout << ans;
}



#include <iostream>
#include <vector>
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

int cnt[2];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    int one = 0,zero = 0,ans = 0;
    string s;cin >> s;

    cnt[s[0] - '0']++;

    for(int i=1;i<s.size();i++){
        if(s[i] != s[i-1]) cnt[s[i] - '0']++;
    }

    cout << min(cnt[0],cnt[1]);

}

