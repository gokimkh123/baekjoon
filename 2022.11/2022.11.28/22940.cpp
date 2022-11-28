// 난이도 : 골드1, 유형 : 수학, 가우스조르단 소거법

#include <bits/stdc++.h>
using namespace std;

void MakePivot(int n, vector<vector<double>> &matrix){
    for(int i=0;i<n;i++) {
        int idx;
        double MAXVAL = abs(matrix[i][i]);

        for (int j = i + 1; j < n; j++) {
            double VAL = abs(matrix[j][i]);

            if (VAL > MAXVAL) {
                MAXVAL = VAL;
                idx = j;
            }
        }

        if (MAXVAL != abs(matrix[i][i])) {
            for (int j = 0; j < n + 1; j++) {
                double temp = matrix[i][j];
                matrix[i][j] = matrix[idx][j];
                matrix[idx][j] = temp;
            }
        }
    }
}

bool MakeGaussian(int n, vector<vector<double>> &matrix){
    for(int i=0;i<n;i++) {
        if (matrix[i][i] == 0)
            return false;

        for (int j = i + 1; j < n; j++) {
            double temp = matrix[j][i] / matrix[i][i];
            for (int k = 0; k < n + 1; k++)
                matrix[j][k] = matrix[j][k] - (temp * matrix[i][k]);
        }
    }
    return true;
}

void MakeAns(int n, vector<vector<double>> &matrix){
    for (int i = n - 1; i >= 0; i--){
        for (int k = i + 1; k < n; k++)
            matrix[i][n] = matrix[i][n] - matrix[i][k] * matrix[k][n];

        matrix[i][n] = matrix[i][n] / matrix[i][i];
    }
}
int main() {
    ios_base::sync_with_stdio(false);

    int n;
    vector<vector<double>> matrix;
    cin >> n;

    matrix.resize(n, vector<double>(n + 1));

    for (int row = 0; row < n; row++)
        for (int col = 0; col < n + 1; col++)
            cin >> matrix[row][col];

    MakePivot(n, matrix);
    MakeGaussian(n, matrix);
    MakeAns(n, matrix);

    for(int i=0;i<n;i++)
        cout << matrix[i][n] << " ";
}
