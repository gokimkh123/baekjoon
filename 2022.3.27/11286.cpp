//난이도 : 실버1, 유형 : 우선순위 큐

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<p>
#define F first
#define S second
using namespace std;

priority_queue<p,vc,greater<>> q;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,x;

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> x;

        if(x) q.push({abs(x),x});
        else{
            if(q.empty()) cout << "0\n";
            else{
                cout << q.top().second << "\n";
                q.pop();
            }
        }
    }
}

