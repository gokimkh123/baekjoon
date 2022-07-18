//난이도 : 골드4, 유형 : 백트래킹

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

int arr[10][10];
bool on;
vector<p> idx;

bool Row(int x,int y){
    for(int i=0;i<9;i++){
        if(y == i) continue;
        if(arr[x][y] == arr[x][i]) return false;
    }

    return true;
}

bool Col(int x,int y){
    for(int i=0;i<9;i++){
        if(x == i) continue;
        if(arr[x][y] == arr[i][y]) return false;
    }

    return true;
}

bool square(int x,int y){
    int a = (x / 3) * 3, b = (y / 3) * 3;
    for(int i=a;i<a+3;i++){
        for(int j=b;j<b+3;j++){
            if(x == i && y == j) continue;
            if(arr[x][y] == arr[i][j]) return false;
        }
    }
    return true;
}

void back(int num){
    if(on) return;

    if(num >= idx.size()){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
                cout << arr[i][j] << " ";
            cout << "\n";
        }
        on = true;
        return;
    }

    int x = idx[num].first, y = idx[num].second;

    for(int k=1;k<=9;k++){
        arr[x][y] = k;

        if(Row(x,y) && Col(x,y) && square(x,y)) back(num+1);
        arr[x][y] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> arr[i][j];
            if(!arr[i][j]) idx.emplace_back(i,j);
        }
    }

    back(0);

}

