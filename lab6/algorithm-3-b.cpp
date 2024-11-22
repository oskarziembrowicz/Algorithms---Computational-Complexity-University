#include <iostream>

using namespace std;

void printField(long long** field, int height, int width) {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            cout << field[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void addToField(long long** arr, int rows, int cols, int x1, int y1, int x2, int y2, long long amount) {
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

void prefixSum(long long** arr, int rows, int cols) {
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
        for (int j=1; j<cols; j++) {
            arr[i][j] += (arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1]);
        }
    }
}

long long areaSum(long long** prefixArray, int x1, int y1, int x2, int y2) {
    long long prevInCol = 0, prevInRow = 0, prev = 0;
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

    long long** field = new long long*[fieldRows];

    for (int i=0; i<numberOfAnalisys; i++) {
        // Initialize array with zeros
        for (int j=0; j<fieldRows; j++) {
            field[j] = new long long[fieldCols]();
        }
        // printField(field, fieldRows, fieldCols);

        // Get amount of updates to field
        int updatesAmount;
        cin >> updatesAmount;
        for (int j=0; j<updatesAmount; j++) {
            int x1, x2, y1, y2;
            long long fertilizerAmount;
            cin >> x1 >> y1 >> x2 >> y2 >> fertilizerAmount;
            
            addToField(field, fieldRows, fieldCols, x1, y1, x2, y2, fertilizerAmount);
            // printField(field, fieldRows, fieldCols);
        }

        // Calculate prefix array for the updated field
        prefixSum(field, fieldRows, fieldCols); // This turns it to a normal field
        prefixSum(field, fieldRows, fieldCols); // This gives a prefix array
        // printField(field, fieldRows, fieldCols);

        // Get number of querys
        int numberOfQuerys;
        cin >> numberOfQuerys;

        long long* output = new long long[numberOfQuerys];

        for (int j=0; j<numberOfQuerys; j++) {
            // Query
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            output[j] = areaSum(field, x1, y1, x2, y2);
        }

        // Show output for this analisys
        for (int j=0; j<numberOfQuerys; j++) {
            cout << output[j] << " ";
        }
        cout << "\n";

        // Clear memory
        for (int j=0; j<fieldRows; j++) {
            delete[] field[j];
        }
        delete[] output;
    }

    // Clear field
    delete[] field;

    return 0;
}