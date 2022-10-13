// 난이도: 실버4, 유형 : 수학

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tu;
typedef vector<unsigned char> vc;

bool isPrime(int k, vc &arr){
    return arr[k >> 3] & (1 << (k & 7));
}
void Set(int k, vc &arr){
    arr[k >> 3] &= ~ (1 << (k & 7));
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vc arr((1000 + 7) / 8 + 1, 255);

    int n, k;

    cin >> n >> k;

    for(int i=2;i<=n;i++){
        if(!isPrime(i, arr)) continue;

        k--;
        if(!k){
            cout << i;
            return 0;
        }

        for(int j=i*i;j<=n;j+=i){
            if(!isPrime(j, arr)) continue;

            k--;
            Set(j,arr);

            if(!k){
                cout << j;
                return 0;
            }
        }
    }

}

