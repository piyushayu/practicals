#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) {
        cout << "Rows and columns must be positive integers.\n";
        return 1;
    }

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter elements of the " << rows << "x" << cols << " matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nThe 2D array is:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}
