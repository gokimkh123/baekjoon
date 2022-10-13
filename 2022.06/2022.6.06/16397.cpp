//난이도 : 골드4, 유형 : bfs

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

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n,t,g;

    cin >> n >> t >> g;

    auto bfs = [&]() -> int{
        bool check[100000] = {0, };
        queue<p> q;

        q.push({n,0}), check[n] = true;

        while(!q.empty()){
            auto cur = q.front();q.pop();

            if(cur.S > t) return -1;
            if(cur.F == g) return cur.S;

            if(cur.F + 1 <= 99999 && !check[cur.F + 1]){
                check[cur.F + 1] = true;
                q.push({cur.F + 1, cur.S + 1});
            }

            if(cur.F != 0 && cur.F * 2 <= 99999){
                string temp = to_string(cur.F * 2);
                temp[0] = (temp[0] - '0' - 1) + '0';
                int num = stoi(temp);

                if(!check[num]){
                    check[num] = true;
                    q.push({num,cur.S + 1});
                }

            }


        }

        return -1;
    };

    int ans = bfs();

    if(ans == -1) cout << "ANG";
    else cout << ans;
}

