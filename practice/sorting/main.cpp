#include <iostream>
#include <vector>
#include "sorting.h"

using namespace std;

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original Array: ";
    printArray(arr);

    vector<int> arr_copy = arr;
    cout << "Merge Sort: ";
    mergeSort(arr_copy, 0, arr_copy.size() - 1);
    printArray(arr_copy);

    arr_copy = arr;
    cout << "Quick Sort: ";
    quickSort(arr_copy, 0, arr_copy.size() - 1);
    printArray(arr_copy);

    arr_copy = arr;
    cout << "Randomized Quick Sort: ";
    randomizedQuickSort(arr_copy, 0, arr_copy.size() - 1);
    printArray(arr_copy);

    arr_copy = arr;
    cout << "Insertion Sort: ";
    insertionSort(arr_copy);
    printArray(arr_copy);

    arr_copy = arr;
    cout << "Bubble Sort: ";
    bubbleSort(arr_copy);
    printArray(arr_copy);

    arr_copy = arr;
    cout << "Selection Sort: ";
    selectionSort(arr_copy);
    printArray(arr_copy);

    return 0;
}
