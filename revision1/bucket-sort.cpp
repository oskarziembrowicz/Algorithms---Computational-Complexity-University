#include <iostream>
#include <vector>

using namespace std;

void printArray(float* arr, int size) {
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void mergeSort(vector<float>& arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    // Merging
    int leftSize = mid+1-start;
    int rightSize = end-mid;
    float* leftArr = new float[leftSize];
    float* rightArr = new float[rightSize];
    
    for (int i=0; i<leftSize; i++) {
        leftArr[i] = arr[start+i];
    }
    for (int i=0; i<rightSize; i++) {
        rightArr[i] = arr[mid+1+i];
    }

    int leftIter = 0, rightIter = 0, mainIter = start;

    while (leftIter < leftSize && rightIter < rightSize) {
        if (leftArr[leftIter] <= rightArr[rightIter]) {
            arr[mainIter++] = leftArr[leftIter++];
        } else {
            arr[mainIter++] = rightArr[rightIter++];
        }
    }

    while (leftIter < leftSize) {
        arr[mainIter++] = leftArr[leftIter++];
    }
    while (rightIter < rightSize) {
        arr[mainIter++] = rightArr[rightIter++];
    }

    delete[] leftArr;
    delete[] rightArr;
}

void bucketSort(float* arr, int n) {
    vector<float>* buckets = new vector<float>[n];
    for (int i=0; i<n; i++) {
        int index = arr[i]*n;
        buckets[index].push_back(arr[i]);
    }

    // Sort each bucket
    int iter = 0;
    for (int i=0; i<n; i++) {
        mergeSort(buckets[i], 0, buckets[i].size()-1);
        for (int j=0; j<buckets[i].size(); j++) {
            arr[iter++] = buckets[i][j];
        }
    }

    delete[] buckets;
}


int main() {
    int size = 10;
    float* arr = new float[size] {0.2, 0.11, 0.45, 0.432, 0.78, 0.900, 0.89435, 0.22, 0.1};

    bucketSort(arr, size);

    printArray(arr, size);

    return 0;
}