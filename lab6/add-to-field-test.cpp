#include <iostream>

using namespace std;

void printField(int** field, int height, int width) {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            cout << field[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
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

int main() {
    int fieldRows = 10, fieldCols = 10;
    int** field = new int*[fieldRows];
    for (int j=0; j<fieldRows; j++) {
            field[j] = new int[fieldCols]();
        }
    printField(field, fieldRows, fieldCols);

    addToField(field, fieldRows, fieldCols, 0, 0, 5, 5, 1);
    printField(field, fieldRows, fieldCols);

    cout << "Checkpoint 1\n";
    addToField(field, fieldRows, fieldCols, 5, 5, 9, 9, 1);
    cout << "Checkpoint 5\n";
    printField(field, fieldRows, fieldCols);

    return 0;
}