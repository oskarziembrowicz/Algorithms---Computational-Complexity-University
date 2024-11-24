#include <iostream>

using namespace std;

void printMatrix(int** matrix, int rows, int cols) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void prefixSum(int** matrix, int rows, int cols) {
    // Sum first column
    for (int i=1; i<rows; i++) {
        matrix[i][0] += matrix[i-1][0];
    }
    // Sum first row
    for (int j=1; j<cols; j++) {
        matrix[0][j] += matrix[0][j-1];
    }
    // Sum the rest
    for (int i=1; i<rows; i++) {
        for (int j=1; j<cols; j++) {
            matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
        }
    }
}

int getAreaSum(int** prefixMatrix, int x1, int y1, int x2, int y2) {
    int upper = 0, left = 0, diagonal = 0;
    if (x1 > 0) {
        left = prefixMatrix[y2][x1-1];
    }
    if (y1 > 0) {
        upper = prefixMatrix[y1-1][x2];
    }
    if (x1 > 0 && y1 > 0) {
        diagonal = prefixMatrix[y1-1][x1-1];
    }
    return prefixMatrix[y2][x2] - left - upper + diagonal;
}

void addToArea(int** matrix, int rows, int cols, int x1, int y1, int x2, int y2, int amount) {
    matrix[y1][x1] += amount;
    if (y2 < rows-1) {
        matrix[y2+1][x1] -= amount;
    }
    if (x2 < cols-1) {
        matrix[y1][x2+1] -= amount;
    }
    if (x2 < cols-1 && y2 < rows-1) {
        matrix[y2+1][x2+1] += amount;
    }
}

int main() {
    int rows = 10, cols = 10;
    int** matrix = new int*[rows];
    for (int i=0; i<rows; i++) {
        matrix[i] = new int[cols]();
    }
    // matrix[0] = new int[cols] {10, 20, 30};
    // matrix[1] = new int[cols] {5, 10, 20};
    // matrix[2] = new int[cols] {2, 4, 6};

    // printMatrix(matrix, rows, cols);

    addToArea(matrix, rows, cols, 0, 0, 5, 5, 1);
    addToArea(matrix, rows, cols, 5, 5, 9, 9, 1);
    addToArea(matrix, rows, cols, 1, 1, 5, 9, 2);
    addToArea(matrix, rows, cols, 6, 1, 9, 7, 2);

    printMatrix(matrix, rows, cols);

    prefixSum(matrix, rows, cols);
    printMatrix(matrix, rows, cols);
    prefixSum(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    cout << getAreaSum(matrix, 2, 3, 2, 9) << "\n";     // Should be: 17

    return 0;
}