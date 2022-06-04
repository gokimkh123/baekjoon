//난이도 : 골드3, 유형 : 그리디, 우선순위 큐

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef tuple<int,int,int> tu;
typedef vector<l> vc;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    priority_queue<l,vc,greater<>> q;

    l n,a,ans = 0,b;

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> a;

        q.push(a);
    }

    if(n == 1){
        cout << 0;
        return 0;
    }

    while(1){

        a = q.top();q.pop();
        b = q.top();q.pop();
        ans += a + b;

        if(q.empty()){
            cout << ans;
            return 0;
        }
        q.push(a+b);

    }
}

