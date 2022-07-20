//난이도 : 골드5, 유형 : 완전탐색

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

int n, m, k, rm[11], ans = INF;

void Find(string num){
    for(int i=0;i<10;i++){
        if(rm[i]) continue;

        string temp = num + to_string(i);
        ans = min(ans, int(temp.length() + abs(n - stoi(temp))));

        if(temp.length() <= 6) Find(temp);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;

    ans = min(ans, abs(100 - n));

    for(int i=0;i<m;i++){
        cin >> k;
        rm[k] = 1;
    }

    if(m == 10) cout << ans;
    else{
        Find("");
        cout << ans;
    }

}
