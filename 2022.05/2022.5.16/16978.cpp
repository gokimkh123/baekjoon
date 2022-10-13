//난이도 : 플레3, 유형 : 세그먼트 트리, 오프라인 쿼리

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<l,l> p;
typedef tuple<l,l,l,l> tu;
typedef vector<tu> vc;

l arr[100001],tree[100001*4];

l init(int st,int en,int node){
    if(st == en) return tree[node] = arr[st];

    int mid = (st + en) / 2;

    return tree[node] = init(st,mid,node*2) + init(mid+1,en,node*2+1);
}

l Sum(int st,int en,int node,int L,int R){
    if(R < st || L > en) return 0;
    if(L <= st && en <= R) return tree[node];

    int mid = (st + en) / 2;

    return Sum(st,mid,node*2,L,R) + Sum(mid+1,en,node*2+1,L,R);
}

void Update(int st,int en,int node,int idx,l val){
    if(idx < st || idx > en) return;

    if(st == en){
        tree[node] = val;
        return;
    }

    int mid = (st + en) / 2;

    Update(st,mid,node*2,idx,val);
    Update(mid+1,en,node*2+1,idx,val);

    tree[node] = tree[node*2] + tree[node*2+1];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    vc temp;
    vector<p> ans;
    queue<p> query;
    int n,m,a,b,c,d;

    cin >> n;

    for(int i=0;i<n;i++)
        cin >> arr[i];

    cin >> m;

    init(0,n-1,1);

    int cnt = 0;
    while(m--){
        cin >> a;

        if(a == 1) {
            cin >> b >> c;
            query.push({b,c});
        }
        else{
            cin >> b >> c >> d;
            temp.emplace_back(b,c,d,cnt++);
        }
    }
    sort(all(temp));
    cnt = 1;
    for(auto &i : temp){
        tie(a,b,c,d) = i;

        while(a >= cnt && !query.empty()){
            Update(0,n-1,1,query.front().F-1,query.front().S);
            query.pop();
            cnt++;
        }
        ans.emplace_back(d,Sum(0,n-1,1,b-1,c-1));

    }

    sort(all(ans));
    for(auto &i : ans)
        cout << i.S << "\n";
}

