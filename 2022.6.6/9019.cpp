//난이도 : 골드4, 유형 : bfs

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,string> p;
typedef tuple<int,int,int> tu;
typedef vector<int> vc;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t,a,b;
    cin >> t;

    auto bfs = [&](){
        bool check[10001] = {0, };
        queue<p> q;
        q.push({a,""}),check[a] = true;


        while(!q.empty()){
            auto now = q.front();q.pop();
            int cur = now.F;
            string str = now.S;

            if(cur == b) return str;

            int DNum = (cur * 2) % 10000;
            if(!check[DNum]){
                check[DNum] = true;
                q.push({DNum, str + 'D'});
            }

            int SNum = (cur - 1) < 0 ? 9999 : cur - 1;

            if(!check[SNum]){
                check[SNum] = true;
                q.push({SNum, str + 'S'});
            }

            int dL = (cur % 1000) * 10 + cur / 1000;
            if(!check[dL]){
                check[dL] = true;
                q.push({dL, str + 'L'});
            }

            int dR = (cur % 10) * 1000 + cur / 10;
            if(!check[dR]){
                check[dR] = true;
                q.push({dR, str + 'R'});
            }
        }

    };

    while(t--){
        cin >> a >> b;

        cout << bfs() << "\n";
    }
}

