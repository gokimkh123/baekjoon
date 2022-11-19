// 난이도 : 브론즈 3, 유형 : 수학

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int, int> tu;
typedef vector<ll> vc;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;


    for(int TC=1;TC<=t;TC++){
        int flag = false;
        vc v(3);

        for(auto &i : v)
            cin >> i;

        do{
            if(v[0] * v[0] == v[1] * v[1] + v[2] * v[2]){
                flag = true;
                break;
            }
        }while(next_permutation(all(v)));

        cout << "Scenario #" <<  TC << ":\n";

        if(flag) cout << "yes";
        else cout << "no";
        cout << "\n\n";
    }
}
