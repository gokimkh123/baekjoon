//난이도 : 실버1, 유형 : 에라토스테네스의 체

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<int>
#define F first
#define S second
using namespace std;

unsigned char arr[(1000000 + 7) / 8 + 1];

bool isPrime(int k){
    return arr[k >> 3] & (1 << (k & 7));
}

void Set(int k){
    arr[k >> 3] &= ~(1 << (k & 7));
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n,a,b;

    memset(arr,255, sizeof(arr));
    Set(0);
    Set(1);

    for(int i=2;i*i<=1000000;i++){
        if(isPrime(i)){
            for(int j=i*i;j<=1000000;j+=i)
                Set(j);
        }
    }

    while(1){
        bool on = false;
        cin >> n;
        if(!n) return 0;

        for(int i=3;i<n-2;i++){
            if(!isPrime(i)) continue;
            b = n - i;
            if(!isPrime(b)) continue;

            a = i;
            on = true;
            break;
        }

        if(on) cout << n << " = " << a << " + " << b << "\n";
        else cout << "Goldbach's conjecture is wrong.\n";
    }
}
y
