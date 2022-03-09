//난이도 : 골드3, 유형 : 그리디

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

struct L{int s,e,box;};

L a[10001];
int sum[10001],ans;
bool cmp(L &x, L &y){
    if(x.e < y.e) return true;
    else if(x.e == y.e) return x.s < y.s;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,c,m;

    cin >> n >> c >> m;

    for(int i=0;i<m;i++){
        int x,y,z;
        cin >> x >> y >> z;

        a[i].s = x, a[i].e = y, a[i].box = z;
    }

    sort(a,a+m,cmp);

    for(int i=0;i<m;i++){
        int Mbox = 0;

        for(int j=a[i].s;j<a[i].e;j++)
            Mbox = max(Mbox,sum[j]);

        int temp = min(a[i].box,c - Mbox);
        ans += temp;

        for(int j=a[i].s;j<a[i].e;j++)
            sum[j] += temp;
    }

    cout << ans;
}
