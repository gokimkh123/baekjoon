//난이도 : 골드3, 유형 : 비트마스크

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<unsigned char>
#define F first
#define S second
using namespace std;

bool check(int k,vc &v){
    return v[k >> 3] & (1 << (k & 7));
}
void Set(int k,vc &v){
    v[k >> 3] &= ~(1 << (k & 7));
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    vc v((33554432 + 7) / 8 + 1,255);

    int n;
    while(cin >> n){
        if(check(n,v)){
            cout << n << " ";
            Set(n,v);
        }
    }
}

