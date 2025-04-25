#ifndef SORTING_H
#define SORTING_H

#include <vector>

// Merge Sort
void mergeSort(std::vector<int>& arr, int left, int right);

// Quick Sort
void quickSort(std::vector<int>& arr, int low, int high);

// Randomized Quick Sort
void randomizedQuickSort(std::vector<int>& arr, int low, int high);

// Insertion Sort
void insertionSort(std::vector<int>& arr);

// Bubble Sort
void bubbleSort(std::vector<int>& arr);

// Selection Sort
void selectionSort(std::vector<int>& arr);

// Utility Functions
void printArray(const std::vector<int>& arr);

#endif
