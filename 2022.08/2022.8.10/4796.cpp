//난이도 : 브론즈 1, 유형 : 수학

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
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    l L, P, V, cnt = 1;

    while(1){
        cin >> L >> P >> V;

        if(L == 0) return 0;

        cout << "Case " << cnt++ << ": " << L * (V / P) + min(V % P, L) << "\n";

    }

}

