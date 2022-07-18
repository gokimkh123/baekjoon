//난이도 : 골드 2, 유형 : 우선순위 큐

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

priority_queue<int,vector<int>,greater<>> MinQ;
priority_queue<int,vector<int>,less<>> MaxQ;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,num,temp;
    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> num;
        if(i % 2 == 0) temp = MaxQ.top();

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

        if(i % 2 == 0) cout << min(temp,MaxQ.top()) << "\n";
        else cout << MaxQ.top() << "\n";
    }
}
