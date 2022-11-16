// 난이도 : 실버4, 유형 : 구현, 그리디

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int, int> tu;
typedef vector<int> vc;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, Left, Right, ans = 0;

    cin >> n;

    vc v(n), temp = {100, 50, 20, 10, 5, 2, 1};

    for(auto &i : v)
        cin >> i;

    Left = v[0];
    Right = v[1];

    for(int i=2;i<n;i++){
        if(Left == Right) Left += v[i];
        else{
            if(Left > Right) Right += v[i];
            else if(Left < Right) Left += v[i];
        }
    }

    int Sum = abs(Left - Right);

    for(auto &i : temp){
        ans += Sum / i;
        Sum %= i;
    }

    cout << ans;

}
