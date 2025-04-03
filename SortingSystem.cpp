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
    while (true) {
        int n;
        cout << "Enter the number of items to sort:";
        cin >> n;
        string data_test[n];
        for (int i = 0; i < n; i++) {
            cout << "Enter data " << i + 1 << ":";
            cin >> data_test[i];
        }
        int choice;
        cout<<"Select a sorting algorithm:\n";
        cout<<"1. Insertion Sort\n";
        cout<<"2. Selection Sort\n";
        cout<<"3. Bubble Sort\n";
        cout<<"4. Shell Sort\n";
        cout<<"5. Merge Sort\n";
        cout<<"6. Quick Sort\n";
        cout<<"7. Count Sort\n";
        cout<<"8. Radix Sort\n";
        cout<<"9. Bucket Sort\n";
        cout<<"Enter your choice (1-9):";
        while (true) {
            cin>>choice;
            switch (choice) {
                case 1:
                    //insertionSort();
                        break;
                case 2:
                    //selectionSort();
                        break;
                case 3:
                    //bubbleSort();
                        break;
                case 4:
                    //shellSort();
                        break;
                case 5:
                    //mergeSort();
                        break;
                case 6:
                    //quickSort();
                        break;
                case 7:
                    //countSort();
                        break;
                case 8:
                    //radixSort();
                        break;
                case 9:
                    //bucketSort();
                        break;
                default:
                    cout<<"Wrong choice, Please Enter your choice (1-9):";
                continue; //wrong input so cin again
            }
            break;
        }
        char choice2;
        cout<<"Do you want sort another dataset? (y/n):";
        while (true) {
            cin>>choice2;
            switch (choice2) {
                case 'y':
                    break;
                case 'n':
                    cout<<"Thank you for using the sorting system! Goodbye!";
                    return;
                default:
                    cout<<"Wrong choice, Please Enter your choice (y/n):";
                    continue;
            }
            break;
        }
    }}

