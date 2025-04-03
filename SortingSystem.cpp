//
// Created by akhte on 4/3/2025.
//
#include "SortingSystem.h"

// Constructor
template <typename T>
SortingSystem<T>::SortingSystem(int n) {
    size = n;
    data = new T[size];
}

// Destructor
template <typename T>
SortingSystem<T>::~SortingSystem() {
    delete[] data;
}

// Sorting algorithms

template <typename T>
void SortingSystem<T>::insertionSort() {
    // TODO: Implement Insertion Sort
}

template <typename T>
void SortingSystem<T>::selectionSort() {
    // TODO: Implement Selection Sort
}

template <typename T>
void SortingSystem<T>::bubbleSort() {
    // TODO: Implement Bubble Sort
}

template <typename T>
void SortingSystem<T>::shellSort() {
    // TODO: Implement Shell Sort
}

template <typename T>
void SortingSystem<T>::mergeSort(int left, int right) {
    // TODO: Implement Merge Sort
}

template <typename T>
void SortingSystem<T>::quickSort(int left, int right) {
    // TODO: Implement Quick Sort
}

template <typename T>
void SortingSystem<T>::countSort() {
    // TODO: Implement Count Sort (Only for int)
}

template <typename T>
void SortingSystem<T>::radixSort() {
    // TODO: Implement Radix Sort (Only for int)
}

template <typename T>
void SortingSystem<T>::bucketSort() {
    // TODO: Implement Bucket Sort
}

// Helper functions (TODO: Implement them)
template <typename T>
void SortingSystem<T>::merge(int left, int mid, int right) {
    // TODO: Implement Merge Sort Helper
}

template <typename T>
int SortingSystem<T>::partition(int low, int high) {
    // TODO: Implement Quick Sort Helper
}

// Utility functions (TODO: Implement them)
template <typename T>
void SortingSystem<T>::displayData() {
    // TODO: Implement function to display data
}

template <typename T>
void SortingSystem<T>::measureSortTime(void (SortingSystem::*sortFunc)()) {
    // TODO: Implement sorting time measurement
}

template <typename T>
void SortingSystem<T>::showMenu() {
    // TODO: Implement user interaction menu
}

