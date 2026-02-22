#include <bits/stdc++.h>
using namespace std;

int boardA[1001][1001], boardB[1001][1001];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int H, W, X, Y;
    cin >> H >> W >> X >> Y;

    for (int i = 0; i < H + X; i++)
        for (int j = 0; j < W + Y; j++)
            cin >> boardB[i][j];

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (boardB[i][j] != 0) boardA[i][j]++;

    for (int i = X; i < H + X; i++)
        for (int j = Y; j < W + Y; j++)
            if (boardB[i][j] != 0) boardA[i][j]++;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (boardA[i][j] == 1)
                boardA[i][j] = boardB[i][j];
            else if (boardA[i][j] >= 2)
                boardA[i][j] = boardB[i][j] - boardA[i - X][j - Y];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            cout << boardA[i][j] << " ";
        cout << "\n";
    }


}