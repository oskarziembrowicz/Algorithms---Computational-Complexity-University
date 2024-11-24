#include <iostream>

using namespace std;

void printArray(int* arr, int size) {
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void initiateSumTree(int* tree, int* intputArray, int nodeIndex, int start, int end) {
    if (start == end) {
        tree[nodeIndex] = intputArray[start];
        return;
    }
    int middle = (start + end)/2;
    initiateSumTree(tree, intputArray, nodeIndex*2, start, middle);
    initiateSumTree(tree, intputArray, nodeIndex*2+1, middle+1, end);
    tree[nodeIndex] = tree[nodeIndex*2] + tree[nodeIndex*2+1];
}

int getSum(int* tree, int nodeIndex, int start, int end, int queryStart, int queryEnd) {
    if (queryStart > queryEnd) {
        // Wrong branch - query not in range
        return 0;
    }
    if (start == queryStart && end == queryEnd) {
        return tree[nodeIndex];
    }
    int middle = (start + end)/2;
    int leftSum = getSum(tree, nodeIndex*2, start, middle, queryStart, min(middle, queryEnd));
    int rightSum = getSum(tree, nodeIndex*2+1, middle+1, end, max(middle+1, queryStart), queryEnd);
    return leftSum + rightSum;
}

void update(int* tree, int nodeIndex, int start, int end, int targetIndex, int value) {
    if (start == end) {
        tree[nodeIndex] = value;
        return;
    }

    int middle = (start + end)/2;
    if (targetIndex <= middle) {
        update(tree, nodeIndex*2, start, middle, targetIndex, value);
    } else {
        update(tree, nodeIndex*2+1, middle+1, end, targetIndex, value);
    }
    tree[nodeIndex] = tree[nodeIndex*2] + tree[nodeIndex*2+1];
}

int main() {
    int size = 10;
    int* arr = new int[size] {2, 4, 8, 5, 1, 5, 89, 12, 45, 10};

    int treeSize = size*4;
    int* tree = new int[treeSize]();
    initiateSumTree(tree, arr, 1, 0, size-1);

    // printArray(tree, treeSize);

    cout << getSum(tree, 1, 0, size-1, 2, 7) << "\n";   // Should be: 120

    update(tree, 1, 0, size-1, 2, 10);

    cout << getSum(tree, 1, 0, size-1, 2, 2) << "\n";

    cout << getSum(tree, 1, 0, size-1, 2, 7) << "\n";   // Should be: 122

    return 0;
}