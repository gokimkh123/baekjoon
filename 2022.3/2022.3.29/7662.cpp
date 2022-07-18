//난이도 : 골드5, 유형 : 우선순위 큐, map

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<int>
#define F first
#define S second
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t,k,n;
    char c;
    cin >> t;

    while(t--){
        unordered_map<int,int> check;
        priority_queue<int,vc,greater<>> MinQ; // 오름 차순
        priority_queue<int,vc,less<>> MaxQ; // 내림차순

        cin >> k;

        for(int i=0;i<k;i++) {
            cin >> c >> n;

            if (c == 'I') {
                check[n]++;
                MinQ.push(n);
                MaxQ.push(n);
            }
            else {
                if (n == 1) {
                    while(!MaxQ.empty() && check[MaxQ.top()] == 0) MaxQ.pop();

                    if(MaxQ.empty()) continue;
                    check[MaxQ.top()]--, MaxQ.pop();
                }
                else if (n == -1) {

                    while(!MinQ.empty() && check[MinQ.top()] == 0) MinQ.pop();

                    if(MinQ.empty()) continue;
                    check[MinQ.top()]--, MinQ.pop();
                }
            }
        }
        while(!MaxQ.empty() && check[MaxQ.top()] == 0) MaxQ.pop();
        while(!MinQ.empty() && check[MinQ.top()] == 0) MinQ.pop();

       if(MaxQ.empty() && MinQ.empty()) cout << "EMPTY\n";
       else cout << MaxQ.top() << " " << MinQ.top() << "\n";

    }
}

