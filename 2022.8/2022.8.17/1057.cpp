//난이도 : 실버4, 유형 : 수학

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tu;
typedef vector<int> vc;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n, a, b, ans = 1;

    cin >> n >> a >> b;

    while(n /= 2){
        if((a % 2) + (a / 2) == (b % 2) + (b / 2))   break;

        a = (a % 2) + (a / 2);
        b = (b % 2) + (b / 2);
        ans++;
    }


    cout << ans;

}

