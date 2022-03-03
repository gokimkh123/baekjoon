//난이도 : 실버 1, 유형 : 그리디, bfs


//bfs

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define MAX 1000000000
using namespace std;


l a,b,MIN = MAX ;
unordered_map<l,bool> check;

void bfs(){

    queue<pair<l,l>> q;
    check[a] = true;
    q.push({a,1});

    while(!q.empty()){
        l num = q.front().first,cnt = q.front().second;q.pop();

        if(num == b){
            cout << cnt;
            return;
        }

        if(num * 2 <= b && !check[num*2]){
            q.push({num*2,cnt+1});
            check[num*2] = true;
        }
        if(num * 10 + 1 <= b && !check[num*10+1]){
            q.push({num*10+1,cnt+1});
            check[num*10+1] = true;
        }
    }

    cout << "-1";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> a >> b;

    bfs();
}

//그리디

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define MAX 1000000000
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    l a,b;
    int cnt = 1;

    cin >> a >> b;

    while(1){
        if(b == a) break;

        if((b % 2 != 0 && b % 10 != 1) || b < a){
            cout << "-1";
            return 0;
        }

        if(b % 2 == 0){
            b /= 2;
            cnt++;
        }
        else if(b % 10 == 1){
            b /= 10;
            cnt++;
        }
    }
    cout << cnt;
}
