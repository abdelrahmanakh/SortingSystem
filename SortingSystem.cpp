
#include <iostream>

using namespace std;


template<typename T>
class SortingSystem {
private:
    T *data;  // Dynamic array for storing input data
    int size; // Size of the array

public:
    SortingSystem(int n);  // Constructor
    ~SortingSystem();      // Destructor

    void insertionSort();   // (1) Insertion Sort
    void selectionSort();   // (2) Selection Sort
    void bubbleSort();      // (3) Bubble Sort
    void shellSort();       // (4) Shell Sort
    void mergeSort(int left, int right);  // (5) Merge Sort
    void quickSort(int left, int right);  // (6) Quick Sort
    void countSort();       // (7) Count Sort (Only for int)
    void radixSort();       // (8) Radix Sort (Only for int)
    void bucketSort();      // (9) Bucket Sort
    void merge(int left, int mid, int right);  // Merge Sort Helper
    int partition(int low, int high);         // Quick Sort Helper

    void displayData();  // Print the current state of the array
    void measureSortTime(void (SortingSystem::*sortFunc)()); // Measure sorting time

    void showMenu();  // Display menu for user interaction
    void display();
};

// Constructor
template<typename T>
SortingSystem<T>::SortingSystem(int n) {
    size = n;
    data = new T[size];
}

// Destructor
template<typename T>
SortingSystem<T>::~SortingSystem() {
    delete[] data;
}

// Sorting algorithms

template<typename T>
void SortingSystem<T>::insertionSort() {
    for (int i = 1; i < size; i++) {
        T key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
        cout << "Iter " << i << " : ";
        this->display();
    }
    cout << "sorted data : ";
    this->display();
}

template<typename T>
void SortingSystem<T>::selectionSort() {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (data[j] < data[minIndex])
                minIndex = j;
        }
        T temp = data[minIndex];
        data[minIndex] = data[i];
        data[i] = temp;
        cout << "Iter " << i + 1 << " : ";
        this->display();
    }
    cout << "sorted data : ";
    this->display();
}

template<typename T>
void SortingSystem<T>::bubbleSort() {
    // TODO: Implement Bubble Sort
}

template<typename T>
void SortingSystem<T>::shellSort() {
    // TODO: Implement Shell Sort
}

template<typename T>
void SortingSystem<T>::mergeSort(int left, int right) {
    if (left == right)
        return;
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);

    cout << "Array after merge: ";
    display();
    cout << endl;
}

template<typename T>
void SortingSystem<T>::quickSort(int left, int right) {
    // TODO: Implement Quick Sort
}

template<typename T>
void SortingSystem<T>::countSort() {
    // TODO: Implement Count Sort (Only for int)
}

template<typename T>
void SortingSystem<T>::radixSort() {
    // TODO: Implement Radix Sort (Only for int)
}

template<typename T>
void SortingSystem<T>::bucketSort() {
    // TODO: Implement Bucket Sort
}

// Helper functions (TODO: Implement them)
template<typename T>
void SortingSystem<T>::merge(int left, int mid, int right) {
    T L[mid - left + 1], R[right - mid];
    for (int k = left; k <= mid; ++k)
        L[k - left] = data[k];
    for (int k = mid + 1; k <= right; ++k)
        R[k - mid - 1] = data[k];

    cout << "Left array: [";
    for (int i = 0; i < mid - left + 1; ++i) {
        cout << " " << L[i] << ", "[i == mid - left];
    }
    cout << "]";

    cout << " Right array: [";
    for (int i = 0; i < right - mid; ++i) {
        cout << " " << R[i] << ", "[i == right - mid - 1];
    }
    cout << "]" << endl;

    int i = 0, j = 0;
    while (i < mid - left + 1 && j < right - mid) {
        if (L[i] <= R[j]) {
            data[left + i + j] = L[i];
            ++i;
        } else {
            data[left + i + j] = R[j];
            ++j;
        }
    }
    while (i < mid - left + 1) data[left + i + j] = L[i], ++i;
    while (j < right - mid) data[left + i + j] = R[j], ++j;

    cout << "Merged result: [";
    for (int k = left; k <= right; ++k) {
        cout << " " << data[k] << ", "[k == right];
    }
    cout << "]" << endl;

}

template<typename T>
int SortingSystem<T>::partition(int low, int high) {
    // TODO: Implement Quick Sort Helper
}

// Utility functions (TODO: Implement them)
template<typename T>
void SortingSystem<T>::displayData() {
    // TODO: Implement function to display data
}

template<typename T>
void SortingSystem<T>::measureSortTime(void (SortingSystem::*sortFunc)()) {
    // TODO: Implement sorting time measurement
}

template<typename T>
void SortingSystem<T>::display() {
    cout << "[";
    for (int i = 0; i < size; i++)
        cout << " " << data[i] << ", "[i == size - 1];
    cout << "]" << endl;
}

template<typename T>
void SortingSystem<T>::showMenu() {
    while (true) {
        const int n = this->size;
        for (int i = 0; i < n; i++) {
            cout << "Enter data " << i + 1 << ": ";
            T ele;
            cin >> ele;
            data[i] = ele;
        }
        int choice;
        cout << "Select a sorting algorithm:\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Shell Sort\n";
        cout << "5. Merge Sort\n";
        cout << "6. Quick Sort\n";
        cout << "7. Count Sort\n";
        cout << "8. Radix Sort\n";
        cout << "9. Bucket Sort\n";
        cout << "Enter your choice (1-9): ";
        while (true) {
            cin >> choice;
            switch (choice) {
                case 1:
                    insertionSort();
                    break;
                case 2:
                    selectionSort();
                    break;
                case 3:
                    //bubbleSort();
                    break;
                case 4:
                    //shellSort();
                    break;
                case 5:
                    mergeSort(0, n - 1);
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
                    cout << "Wrong choice, Please Enter your choice (1-9):";
                    continue; //wrong input so cin again
            }
            break;
        }
        char choice2;
        cout << "Do you want sort another dataset? (y/n):";
        while (true) {
            cin >> choice2;
            switch (choice2) {
                case 'y':
                    break;
                case 'n':
                    cout << "Thank you for using the sorting system! Goodbye!";
                    return;
                default:
                    cout << "Wrong choice, Please Enter your choice (y/n):";
                    continue;
            }
            break;
        }
    }
}


int main() {
    int type;
    cout << "Enter type of data :\n";
    cout << "1 - String\n";
    cout << "2 - Integer\n";
    cout << "3 - Float\n";
    cout << "4 - Character\n";
    cin >> type;
    cout << "Enter size of data : " << '\n';
    int size;
    cin >> size;
    if (type == 1) {
        SortingSystem<string> sys(size);
        sys.showMenu();
    } else if (type == 2) {
        SortingSystem<int> sys(size);
        sys.showMenu();
    } else if (type == 3) {
        SortingSystem<float> sys(size);
        sys.showMenu();
    } else if (type == 4) {
        SortingSystem<char> sys(size);
        sys.showMenu();
    }

    return 0;
}
