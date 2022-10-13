// 난이도 : 실버4, 유형 : 이분탐색

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

    int a, b, ans = 0;

    cin >> a >> b;

    vc A(a), B(b), temp;

    for(auto &i : A)
        cin >> i;

    for(auto &i : B)
        cin >> i;

    sort(all(B));

    for(auto &i : A){
        if(!binary_search(all(B), i)){
            ans++;
            temp.push_back(i);
        }
    }

    cout << ans << "\n";

    sort(all(temp));

    for(auto &i : temp)
        cout << i << " ";


}

