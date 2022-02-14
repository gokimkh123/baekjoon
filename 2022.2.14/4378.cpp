//난이도 : 실버5, 유형 : 구현

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <deque>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

string s[5]{
    "`1234567890-=",
    "QWERTYUIOP[]\\",
    "ASDFGHJKL;\'",
    "ZXCVBNM,./"
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    string str;

    while(getline(cin,str)) {
        for (auto &i: str) {
            if (i == ' ') cout << ' ';
            else {
                bool check = false;
                for (int j = 0; j < 4; j++) {
                    for (int jj = 0; jj < s[j].size(); jj++) {
                        if (i == s[j][jj]) {
                            cout << s[j][jj - 1];
                            check = true;
                            break;
                        }
                    }
                    if (check) break;
                }
            }
        }
        cout << "\n";
    }

}

