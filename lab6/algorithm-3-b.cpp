#include <iostream>

using namespace std;

// WORKS UP TO COMMENTED

void printField(int** field, int height, int width) {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            cout << field[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void updateField(int** field, int x1, int y1, int x2, int y2, int amount) {
    for (int i=y1; i<=y2; i++) {
        for (int j=x1; j<=x2; j++) {
            field[i][j] += amount;
        }
    }
}

void addToField(int** arr, int rows, int cols, int x1, int y1, int x2, int y2, int amount) {
    arr[y1][x1] += amount;
    if (y2 < rows-1) {
        arr[y2+1][x1] -= amount;
    }
    if (x2 < cols-1) {
        arr[y1][x2+1] -= amount;
    }
    if (y2 < rows-1 && x2 < cols-1) {
        arr[y2+1][x2+1] += amount;
    }
}

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
            arr[i][j] += (arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1]);
        }
    }
}

int areaSum(int** prefixArray, int x1, int y1, int x2, int y2) {
    int prevInCol = 0, prevInRow = 0, prev = 0;
    if (x1 > 0 && y1 > 0) {
        prev = prefixArray[y1-1][x1-1];
    }
    if (x1 > 0) {
        prevInCol = prefixArray[y2][x1-1];
    }
    if (y1 > 0) {
        prevInRow = prefixArray[y1-1][x2];
    }
    return prefixArray[y2][x2] - prevInRow - prevInCol + prev;
}

int main() {
    ios_base::sync_with_stdio(false);

    int numberOfAnalisys;
    int fieldCols, fieldRows;
    cin >> numberOfAnalisys >> fieldCols >> fieldRows;

    int** field = new int*[fieldRows];

    for (int i=0; i<numberOfAnalisys; i++) {
        // Initialize array with zeros
        for (int j=0; j<fieldRows; j++) {
            field[j] = new int[fieldCols]();
        }
        printField(field, fieldRows, fieldCols);

        // Get amount of updates to field
        int dataAmount;
        cin >> dataAmount;
        for (int j=0; j<dataAmount; j++) {
            int x1, x2, y1, y2, fertilizerAmount;
            cin >> x1 >> y1 >> x2 >> y2 >> fertilizerAmount;
            
            addToField(field, fieldRows, fieldCols, x1, y1, x2, y2, fertilizerAmount);
            // updateField(field, x1, y1, x2, y2, fertilizerAmount);
            printField(field, fieldRows, fieldCols);
        }

        // Calculate prefix sum for the updated field
        prefixSum(field, fieldRows, fieldCols);
        printField(field, fieldRows, fieldCols);

        // Get number of querys
        // int numberOfQuerys;
        // cin >> numberOfQuerys;

        // int* output = new int[numberOfQuerys];

        // for (int j=0; j<numberOfQuerys; j++) {
        //     // Query
        //     int x1, y1, x2, y2;
        //     cin >> x1 >> y1 >> x2 >> y2;

        //     output[j] = areaSum(field, x1, y1, x2, y2);
        //     // cout << areaSum(field, x1, y1, x2, y2) << " " ;
        // }

        // for (int j=0; j<numberOfQuerys; j++) {
        //     cout << output[j] << " ";
        // }
        // cout << "\n";

        for (int j=0; j<fieldRows; j++) {
            delete[] field[j];
        }
        // delete[] output;
    }

    delete[] field;

    return 0;
}