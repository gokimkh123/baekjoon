// 난이도 : 골드 3, 유형 : 완전탐색, 시뮬레이션

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#define l long long
using namespace std;

int n,m,k,sti[11][11],board[41][41],r,c;
void rotation() {
    int temp[11][11];

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++)
            temp[y][x] = sti[y][x];
    }

    for (int y = 0; y < c; y++) {
        for (int x = 0; x < r; x++)
            sti[y][x] = temp[r - 1 - x][y];
    }
    swap(r, c);
}

int yes(int y,int x) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            if (board[y + i][x + j] == 1 && sti[i][j] == 1) return false;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sti[i][j] == 1) board[y + i][x + j] = 1;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;

    while (k--) {
        cin >> r >> c;

        for (int y = 0; y < r; y++) {
            for (int x = 0; x < c; x++)
                cin >> sti[y][x];
        }

        for (int i = 0; i < 4; i++) {
            bool check = false;

            for (int y = 0; y <= n - r; y++) {
                if (check) break;
                for (int x = 0; x <= m - c; x++) {
                    if (yes(y, x)) {
                        check = true;
                        break;
                    }
                }
            }
            if(check) break;
            rotation();
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            ans += board[i][j];
    }

    cout << ans;
}
