//난이도 : 골드2, 유형 : 우선순위 큐

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    l t,m,num;
    cin >> t;

    while(t--){
        priority_queue<l,vector<l>,greater<>> MinQ;     //오름차순
        priority_queue<l,vector<l>,less<>> MaxQ;        //내림차순
        int cnt = 0;
        cin >> m;
        cout << m /2 + 1 << "\n";
        for(int i=1;i<=m;i++){
            cin >> num;

            if(MinQ.empty() && MaxQ.empty()) MaxQ.push(num);
            else if(MaxQ.size() > MinQ.size()){
                if(MaxQ.top() > num){
                    MaxQ.push(num);
                    MinQ.push(MaxQ.top());MaxQ.pop();
                }
                else MinQ.push(num);
            }
            else if(MaxQ.size() == MinQ.size()){
                if(MaxQ.top() < num){
                    MinQ.push(num);
                    MaxQ.push(MinQ.top());MinQ.pop();
                }
                else MaxQ.push(num);
            }

            if(i % 2 == 1){
                cout << MaxQ.top() << " ";
                cnt++;
                if(cnt % 10 == 0) cout << "\n";
            }
        }
        cout << "\n";
    }

}


/*
 1. max큐는 내림차순이며 top값이 항상 중앙값이 된다.
 2. min큐는 오름차순이며 max큐의 top값보다 항상 크다.
 3. 처음 초기값은 입력받는 수 이다.
 4. i=2부터는 만약 max큐가 min큐보다 사이즈가 크고 max큐의 top값이 inptu값보다 크다면 input값으로 중앙값을 업데이트 시키고
 max큐의 탑값을 min큐로 넣어준다.
 ex) maxQ{1,3,4},minQ{5,6}이면 중앙값은 항상 maxQ의 탑이므로 4가 된다.
 5. 만약 max큐와 min큐의 사이즈가 같고 input값이 max큐의 탑값 보다 크다면 min큐에 input값을 넣고 그중에서 제일 작은값이 중앙값이 되므로 max큐에 넣는다
 ex) maxQ{1,2}, minQ{3,4}일때 중앙값은 3 이므로 maxQ{1,2,3},minQ{4}가 된다.
 6. max큐와 min큐의 사이즈가 같지만 input값이 max큐의 탑값보다 작다면 그냥 max큐에 넣는다.

 */
