#include <iostream>

using namespace std;

void printMatrix(int** field, int height, int width) {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            cout << field[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

// int prefixSum(int** arr, int row, int col) {
//     if (row == 0 && col == 0) {
//         cout << "(0,0): " << arr[0][0] << "\n";
//         return arr[0][0];
//     }
//     if (row == 0 && col > 0) {
//         arr[row][col] = prefixSum(arr, row, col-1) + arr[row][col];
//         cout << "(" << row << "," << col << "): " << arr[row][col] << "\n";
//         return arr[row][col];
//     }
//     if (row > 0 && col == 0) {
//         arr[row][col] = prefixSum(arr, row-1, col) + arr[row][col];
//         cout << "(" << row << "," << col << "): " << arr[row][col] << "\n";
//         return arr[row][col];
//     }
//     cout  << "checpoint" ;
//     arr[row][col] = arr[row][col] + prefixSum(arr, row-1, col) + prefixSum(arr, row, col-1) - prefixSum(arr, row-1, col-1);
//     cout << "(" << row << "," << col << "): " << arr[row][col] << "\n";
//     return arr[row][col];
// }

void prefixSum(int** arr, int rows, int cols) {
    // Sum first column
    for (int i=1; i<rows; i++) {
        arr[i][0] += arr[i-1][0];
    }
    // Sum first row
    for (int j=1; j<cols; j++) {
        arr[0][j] += arr[0][j-1];
    }

    // Prefix sum the rest
    for (int i=1; i<rows; i++) {
        for(int j=1; j<cols; j++) {
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
}

int main() {
    int** arr = new int*[3];
    arr[0] = new int[3] {10, 20, 30};
    arr[1] = new int[3] {5, 10, 20};
    arr[2] = new int[3] {2, 4, 6};

    printMatrix(arr, 3, 3);
    cout << "\n";

    prefixSum(arr, 3, 3);

    // cout << prefixSum(arr, 3, 3) << "\n\n";

    printMatrix(arr, 3, 3);

    return 0;
}