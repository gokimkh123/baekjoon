//난이도 : 실버1, 유형 : 완전탐색, 구현, 시뮬레이션

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#define l long long
#define INF 2e9
using namespace std;

int k;string s[5];

void cw(int num){              //시계
    char st = s[num][7];
    char temp[9];temp[0] = st;
    for(int i=1;i<8;i++)    temp[i] = s[num][i-1];

    for(int i=0;i<8;i++)
        s[num][i] = temp[i];
}

void acw(int num){             //반시계
    char st = s[num][0];
    char temp[9];temp[7] = st;

    for(int i=7;i>0;i--)    temp[i-1] = s[num][i];

    for(int i=0;i<8;i++)
        s[num][i] = temp[i];
}

void right(int num,int dir){        //오른쪽 확인
    for(int i=num;i<4;i++){

        if(i == 3 ||s[i][2] == s[i+1][6]){
            for(int j=num;j<=i;j++){
                if(dir == 1) {cw(j);dir *= -1;}
                else if(dir == -1) { acw(j);dir *= -1;}
            }
            break;
        }

    }
}

void left(int num,int dir){     //왼쪽 확인
    for(int i=num;i>=0;i--){

        if(i == 0 || s[i][6] == s[i-1][2]){
            for(int j=num;j>=i;j--){
                if(dir == 1) {cw(j);dir *= -1;}
                else if(dir == -1) { acw(j);dir *= -1;}
            }
            break;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    for(int i=0;i<4;i++)    // N극:0, S극:1
        cin >> s[i];

    cin >> k;

    while(k--){int num,dir;
        cin >> num >> dir;      // dir = 1 시계, -1 반시계
        num--;

        if(num == 0) right(num,dir);
        else if(num == 3) left(num,dir);
        else if(num == 1 || num == 2){
            char cy[9];
            for(int i=0;i<8;i++)
                cy[i] = s[num][i];

            left(num,dir);
            for(int i=0;i<8;i++)
                s[num][i] = cy[i];
            right(num,dir);
        }
    }
    int ans = 0;

    if(s[0][0] == '1') ans += 1;
    if(s[1][0] == '1') ans += 2;
    if(s[2][0] == '1') ans += 4;
    if(s[3][0] == '1') ans += 8;

    cout << ans;

}


/*

 이해 : 극이 같이 다르면 선택된 톱니바퀴와 반대방향으로 1칸씩회전

 1. string 이차원배열로 사용 한 후 string[num]값을 이용하여 회전
 2. 회전 함수 만들어서 회전하기

    시계 방향 회전 함수 : string[num][i]값을 하나씩 다 뒤로 밀기
    반시계 방향 회전 함수 : string[num][i]값을 하나씩 앞으로 당기기
    오른쪽 확인 함수 : string[num][2] 비교 string[num+1][6]
    왼쪽 확인 함수 : string[num][6] 비교 string[num-1][2]

 */
