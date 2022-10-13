//난이도 : 실버2, 유형 : dp, 수학

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

int memo[1001][1001];
const int mod = 10007;

int bino(int n, int k){
    int &ret = memo[n][k];
    if(ret != 0) return ret % mod;

    if(k == 0 || n == k) return 1;

    return ret = (bino(n-1, k) + bino(n-1, k-1)) % mod;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    cout << bino(n,k);

}

