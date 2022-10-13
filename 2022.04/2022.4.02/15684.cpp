//난이도 : 골드4, 유형 : 백트래킹, 구현

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
#define vc vector<int>
#define F first
#define S second
using namespace std;

bool link[31][11],on;
int n,m,h;

bool check(){
    for(int i=1;i<=n;i++){
        int col = i;
        for(int j=1;j<=h;j++){
            if(link[j][col]) col++;
            else if(link[j][col-1]) col--;
        }

        if(col != i) return false;
    }
    return true;
}

void back(int num,int cnt,int end){
    if(on) return;

    if(cnt > end) return;

    if(cnt == end){
        if(check()) on = true;
        return;
    }

    for(int i=num;i<=h;i++){
        for(int j=1;j<=n;j++){
            if(!link[i][j-1] && !link[i][j] && !link[i][j+1]){
                link[i][j] = true;
                back(i,cnt+1,end);
                link[i][j] = false;
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int a,b;

    cin >> n >> m >> h;

    for(int i=0;i<m;i++){
        cin >> a >> b;

        link[a][b] = true;
    }
    for(int i=0;i<=3;i++){
        back(1,0,i);

        if(on){
            cout << i;
            return 0;
        }
    }
    cout << "-1";
}
