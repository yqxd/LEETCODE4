#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NumMatrix {
   public:
    vector<vector<int>> Matrix;
    NumMatrix(vector<vector<int>>& matrix) {
        Matrix = matrix;
        if (Matrix.size() != 0) {
            for (int i = 1; i < Matrix.size(); i++) {
                for (int j = 0; j < Matrix[0].size(); j++) {
                    Matrix[i][j] = Matrix[i][j] + Matrix[i - 1][j];
                }
            }
            for (int j = 1; j < Matrix[0].size(); j++) {
                for (int i = 0; i < Matrix.size(); i++) {
                    Matrix[i][j] = Matrix[i][j] + Matrix[i][j - 1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (Matrix.size() == 0) {
            return NULL;
        }
        int A1 = 0, B1 = 0, B2 = 0;
        if (!(row1 == 0 || col1 == 0)) {
            A1 = Matrix[row1 - 1][col1 - 1];
        }
        if (!(row1 == 0)) {
            B1 = Matrix[row1 - 1][col2];
        }
        if (!(col1 == 0)) {
            B2 = Matrix[row2][col1 - 1];
        }
        return Matrix[row2][col2] - B1 - B2 + A1;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
    vector<vector<int>> Matrix = {};
    NumMatrix A = NumMatrix(Matrix);
    if (A.Matrix.size() == 0) {
        cout << 1 << endl;
    } else {
        cout << A.Matrix.size() << endl;
    }
}