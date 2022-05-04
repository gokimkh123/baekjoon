//난이도 : 플레5, 유형 : 그리디, 정렬

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef tuple<l,l,l> tu;
typedef vector<tu> vc;

bool check[500001];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    l n,m,a,b,num,Xidx,Yidx,CheckNum;

    cin >> n >> m;

    vc v;

    for(int i=0;i<m;i++){
        cin >> a >> b;

        if(a > b){
            v.push_back({a,b+n,i+1});
            v.push_back({a+n,b+n+n,i+1});
        }
        else{
            v.push_back({a,b,i+1});
            v.push_back({a+n,b+n,i+1});
        }
    }

    sort(all(v),[](tu one,tu second){
        if(get<0>(one) == get<0>(second))
            return get<1>(one) > get<1>(second);

        return get<0>(one) < get<0>(second);
    });

    tie(Xidx,Yidx,CheckNum) = v[0];

    for(int i=1;i<v.size();i++){
        tie(a,b,num) = v[i];

        if(check[num]) continue;

        if(Xidx <= a && b <= Yidx) check[num] = true;
        else if(a <= Xidx && Yidx <= b){
            check[CheckNum] = true;
            CheckNum = num;
            Xidx = a, Yidx = b;
        }
        else if(a <= Yidx) Xidx = min(Xidx,a),Yidx = max(Yidx,b);
        else Xidx = a, Yidx = b;
    }

    for(int i=1;i<=m;i++){
        if(check[i]) continue;
        else cout << i << " ";
    }
}


