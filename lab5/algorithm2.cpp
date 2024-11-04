#include <iostream>
#include <vector>

using namespace std;

struct Noble {
    char initial;
    int number_of_peasants;
    vector<int> peasants;
};

/*
ALGORITHMS
- count sort (families)
- bucket sort
- quick sort
- count sort
- merge sort
*/

float turnToSmall(int num) {
    float result = float(num);
    while (result > 1) {
        result /= 10;
    }
    return result;
}

void quickSort(vector<int> arr, int start, int end) {
    if (start < end) {
        // Set pivot point
        int pivot = arr[end];
        // MAYBE DONT SUBTRACT 1?
        int before_index = (start-1);

        // Swap elements based on pivot
        for (int i=start; i<end; i++) {
            if (arr[i] <= pivot) {
                // PUSH THIS ATHER THE SWAP?
                before_index++;
                swap(arr[before_index], arr[i]);
            }
        }

        // Set pivot in position
        int pivot_index = before_index+1;
        swap(arr[pivot_index], arr[end]);

        // Continue recursively on the two halves
        quickSort(arr, start, pivot_index - 1);
        quickSort(arr, pivot_index + 1, end);
    }
}

void bucketSort(vector<int> input_array) {
    int n = input_array.size();
    vector<float> arr(n);
    vector<float> buckets[n];

    for (int i=0; i<n; i++) {
        // LATER REMOVE arr
        arr[i] = turnToSmall(input_array[i]);
        int tmp = arr[i] * n;
        buckets[tmp].push_back(input_array[i]);
    }

    // Use quick sort to sort the buskets


    int index = 0;
    for (int i=0; i<n; i++) {
        // For each bucket
        for (int j=0; j<buckets[n].size(); j++) {
            // For each element in the bucket
            input_array[index] = buckets[i][j];
            index++;
        }
    }

}

int main() {
    // n - liczba szlachciców
    // s - inicjał szlachcica
    // i - liczba chłopów w majątku szlachcica
    // k - kody chłopów (i-chłopów)
    int number_of_nobles;
    int k;

    // cout << "Enter number of nobles: ";
    cin >> number_of_nobles;

    vector<Noble> nobles(number_of_nobles);

    for (int i=0; i<number_of_nobles; i++ ) {
        char noble_initial;
        int number_of_pesants;
        // cout << "Enter initial of the noble and number of his pesants: ";
        cin >> nobles[i].initial >> nobles[i].number_of_peasants;
        for (int j=0; j<nobles[i].number_of_peasants; j++) {
            int peasant;
            // cout << "Enter peasant code: ";
            cin >> peasant;
            nobles[i].peasants.push_back(peasant);
        }
    }

    for (int i=0; i<nobles.size(); i++) {
        cout << nobles[i].initial << ": ";
        for (int j=0; j<nobles[i].peasants.size(); j++) {
            cout << nobles[i].peasants[j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    return 0;
}