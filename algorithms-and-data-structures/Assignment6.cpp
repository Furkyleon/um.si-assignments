#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

// partition function
int partition(vector<int> & array, int firstIndex, int lastIndex){
    int pe = array[firstIndex]; // pivot
    int l = firstIndex; // left index
    int r = lastIndex; // right index

    while (l<r) {
        while (array[l] <= pe && l < lastIndex)
            l++;
        while (array[r] >= pe && r > firstIndex)
            r--;
        if (l < r)
            swap(array[l], array[r]);
    }
    swap(array[firstIndex], array[r]);
    return r;
}

// classic quicksort function
void quickSort(vector<int> & array, int firstIndex, int lastIndex){
    if (firstIndex < lastIndex){
        int j = partition(array, firstIndex, lastIndex);
        quickSort(array, firstIndex, j-1);
        quickSort(array, j+1, lastIndex);
    }
}

// randomized quick sort function
void randomizedQuickSort(vector<int>& arr, int firstIndex, int lastIndex) {
    if (firstIndex < lastIndex) {
        // Pick random pivot and swap with first
        int randomIndex = firstIndex + rand() % (lastIndex - firstIndex + 1);
        swap(arr[firstIndex], arr[randomIndex]);

        int j = partition(arr, firstIndex, lastIndex);
        randomizedQuickSort(arr, firstIndex, j-1);
        randomizedQuickSort(arr, j+1, lastIndex);
    }
}

// median quick sort function
void medianQuickSort(vector<int>& arr, int firstIndex, int lastIndex) {
    if (firstIndex < lastIndex) {
        // Find the median of first, mid, last
        int mid = firstIndex + (lastIndex - firstIndex) / 2;
        if (arr[firstIndex] > arr[mid])
            swap(arr[firstIndex], arr[mid]);
        if (arr[firstIndex] > arr[lastIndex])
            swap(arr[firstIndex], arr[lastIndex]);
        if (arr[mid] > arr[lastIndex])
            swap(arr[mid], arr[lastIndex]);
        swap(arr[firstIndex], arr[mid]);

        int j = partition(arr, firstIndex, lastIndex);
        medianQuickSort(arr, firstIndex, j-1);
        medianQuickSort(arr, j+1, lastIndex);
    }
}

// selection sort
void selectionSort(vector<int>& arr) {
    int arraySize = arr.size();
    for (int i = 0; i < arraySize - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < arraySize; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    int choice;
    bool running = true;
    bool sortCheck;

    vector<int> sequence;
    int size, sum;

    clock_t start, finish;
    double duration;

    int randomIndex, firstIndex, lastIndex, mid;

    // menu
    while (running) {
        cout << "Quicksort - operation:\n\n";
        cout << "1) Generate random sequence\n";
        cout << "2) Generate increasing sequence\n";
        cout << "3) Generate decreasing sequence\n";
        cout << "4) Print the current sequence\n";
        cout << "5) Check if array is sorted\n";
        cout << "6) Print sum of sequence\n";
        cout << "7) Sort with Quicksort\n";
        cout << "8) Sort with randomized Quicksort\n";
        cout << "9) Sort with median Quicksort\n";
        cout << "10) Sort with any other algorithm\n";
        cout << "0) End\n\n";
        cout << "Operation:";
        cin >> choice;

        // operations
        switch (choice) {
            case 1:
                // generating random sequence
                cout << "Enter a size between 1 and 1.000.000:";
                cin >> size;
                sequence.clear();
                for (int i = 0; i < size; ++i)
                    sequence.push_back(rand() % 100); // random numbers between 0-99
                cout << "\n";

                break;
            case 2:
                // generating increasing sequence (from 1 to size)
                cout << "Enter a size between 1 and 1.000.000:";
                cin >> size;
                sequence.clear();
                for (int i = 1; i <= size; i++){
                    sequence.push_back(i);
                }
                cout << "\n";

                break;
            case 3:
                // generating decreasing sequence (from size to 1)
                cout << "Enter a size between 1 and 1.000.000:";
                cin >> size;
                sequence.clear();
                for (int i = size; i > 0; i--){
                    sequence.push_back(i);
                }
                cout << "\n";

                break;
            case 4:
                // printing the current sequence
                cout << "Sequence: ";
                for (int i = 0; i < sequence.size(); i++){
                    cout << sequence[i] << " ";
                }
                cout << "\n\n";

                break;
            case 5:
                // checking if array is sorted (ascending sort)
                sortCheck = true;
                for (int i = 0; i < sequence.size() - 1; i++) {
                    if (sequence[i + 1] < sequence[i]) {
                        sortCheck = false;
                    }
                }

                if (sortCheck)
                    cout << "The sequence is sorted!\n\n";
                else
                    cout << "The sequence is not sorted!\n\n";

                break;
            case 6:
                // printing sum of sequence
                sum = 0;
                start = clock();
                for (int i : sequence){
                    sum = sum + i;
                }
                finish = clock();
                duration = (double)(finish - start)/CLOCKS_PER_SEC;
                cout << "Sum of sequence is " << sum << " (time: " << duration << ")\n\n";

                break;
            case 7:
                // classic quicksort
                if (!sequence.empty()) {
                    start = clock();
                    quickSort(sequence, 0, sequence.size() - 1);
                    finish = clock();
                    duration = (double) (finish - start) / CLOCKS_PER_SEC;
                    cout << "Sequence is quickly sorted in " << duration << " seconds\n\n";
                }
                else {
                    cout << "Sequence is empty! Please generate a sequence first.\n\n";
                }
                break;
            case 8:
                // randomized quicksort
                if (!sequence.empty()) {
                    start = clock();
                    randomizedQuickSort(sequence, 0, sequence.size() - 1);
                    finish = clock();
                    duration = (double)(finish - start) / CLOCKS_PER_SEC;
                    cout << "Sequence is randomized quickly sorted in " << duration << " seconds\n\n";
                } else {
                    cout << "Sequence is empty! Please generate a sequence first.\n\n";
                }
                break;

            case 9:
                // median quicksort
                if (!sequence.empty()) {
                    start = clock();
                    medianQuickSort(sequence, 0, sequence.size() - 1);
                    finish = clock();
                    duration = (double)(finish - start) / CLOCKS_PER_SEC;
                    cout << "Sequence is median quickly sorted in " << duration << " seconds\n\n";
                } else {
                    cout << "Sequence is empty! Please generate a sequence first.\n\n";
                }
                break;
            case 10:
                // sorting with any other algorithm (selection sort)
                if (!sequence.empty()){
                    start = clock();
                    selectionSort(sequence);
                    finish = clock();
                    duration = (double)(finish - start)/CLOCKS_PER_SEC;
                    cout << "Sequence is sorted with selection sort in " << duration << " seconds\n\n";
                }
                else {
                    cout << "Sequence is empty! Please generate a sequence first.\n\n";
                }
                break;
            case 0:
                // exiting program
                cout << "Exiting program...\n";
                running = false;
                break;
            default:
                cout << "Invalid operation. Please try again.\n\n";
                break;
        }
    }

    return 0;
}
