#include <chrono>
#include <iomanip>
#include <iostream>

using namespace std;


template<typename T>
class SortingSystem {
private:
    T *data; // Dynamic array for storing input data
    int size; // Size of the array

public:
    SortingSystem(int n); // Constructor
    ~SortingSystem(); // Destructor

    void insertionSort(); // (1) Insertion Sort
    void selectionSort(); // (2) Selection Sort
    void bubbleSort(); // (3) Bubble Sort
    void shellSort(); // (4) Shell Sort

    void mergeSort();

    void mergeSort(int left, int right); // (5) Merge Sort

    void quickSort();

    void quickSort(int left, int right); // (6) Quick Sort


    void countSort(); // (7) Count Sort (Only for int)
    void radixSort(); // (8) Radix Sort (Only for int)
    void bucketSort(); // (9) Bucket Sort
    void merge(int left, int mid, int right); // Merge Sort Helper
    int partition(int low, int high); // Quick Sort Helper

    void measureSortTime(void (SortingSystem::*sortFunc)()); // Measure sorting time

    void showMenu(); // Display menu for user interaction
    void displayData(); // Print the current state of the array
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
        displayData();
    }
    cout << "sorted data : ";
    displayData();
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
        displayData();
    }
    cout << "sorted data : ";
    displayData();
}

template<typename T>
void SortingSystem<T>::bubbleSort() {
    cout << "Sorting Using Bubble Sort...\n";
    cout << "Intial Data: ";
    displayData();
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                swapped = true;
            }
            cout << "Iteration (" << i << ", " << j << "):";
            displayData();
        }
        if (!swapped) {
            break;
        }
    }
    cout << "Sorted Data: ";
    displayData();
}

template<typename T>
void SortingSystem<T>::shellSort() {
    cout << "Sorting Using Bubble Sort...\n";
    cout << "Intial Data: ";
    displayData();
    for (int gap = size / 2; gap > 0; gap /= 2) {
        int iteration = 0;
        for (int i = gap; i < size; i++) {
            T temp = data[i];
            int j = i;
            for (; j >= gap && data[j - gap] > temp; j -= gap) {
                data[j] = data[j - gap];
            }
            data[j] = temp;
            iteration++;
            cout << "Iteration " << iteration << " with gap " << gap << ": ";
            displayData();
        }
    }
    cout << "Sorted Data: ";
    displayData();
}


template<typename T>
void SortingSystem<T>::mergeSort() {
    mergeSort(0, size - 1);
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
    displayData();
    cout << endl;
}

template<typename T>
void SortingSystem<T>::quickSort() {
    quickSort(0, size - 1);
}

template<typename T>
void SortingSystem<T>::quickSort(int left, int right) {
    if (left < right) {
        int pivot = partition(left, right);

        cout << "Pivot: " << data[pivot] << " -> [";
        for (int i = left; i < pivot; i++) {
            cout << " " << data[i] << ", "[i == pivot - 1];
        }
        cout << "] " << data[pivot] << " [";
        for (int i = pivot + 1; i <= right; i++) {
            cout << " " << data[i] << ", "[i == right];
        }
        cout << "]" << endl;

        quickSort(left, pivot - 1);
        quickSort(pivot + 1, right);
    }
    if (left == 0 && right == size - 1) {
        cout << "Sorted Data: ";
        displayData();
    }
}

template<typename T>
void SortingSystem<T>::countSort() {
    if constexpr (is_same_v<T, int>) {
        int k = 0;
        for (int i = 0; i < size; i++)
            k = max(k, data[i] + 1);

        auto count = new int[k]();
        for (int i = 0; i < size; i++)
            ++count[data[i]];

        for (int i = 1; i < k; i++)
            count[i] += count[i - 1];

        auto tmp = new int[size];
        for (int i = 0; i < size; i++)
            tmp[i] = data[i];
        for (int i = size - 1; i >= 0; i--) {
            data[--count[tmp[i]]] = tmp[i];
            cout << "Iter " << size - i << " : ";
            displayData();
        }
        cout << "Sorted Data: ";
        displayData();
        delete[] count;
        delete[] tmp;
    } else
        cout << "Invalid algorithm for this datatype\n";
}

template<typename T>
void SortingSystem<T>::radixSort() {
    if constexpr (is_same_v<T, int>) {
        int mx_num = 0;
        for (int i = 0; i < size; i++)
            mx_num = max(mx_num, data[i]);
        int tmp = mx_num;
        int mx_digits = 0;
        while (tmp) {
            tmp /= 10;
            mx_digits++;
        }

        auto kthDigit = [](int x, int k) {
            while (k--)
                x /= 10;
            return x % 10;
        };

        for (int dig = 0; dig < mx_digits; dig++) {
            int m[10] = {};
            int *exp[10];
            for (int i = 0; i < size; i++) {
                int kd = kthDigit(data[i], dig);
                if (!m[kd])
                    exp[kd] = new int;
                exp[kd][m[kd]++] = data[i];
            }
            int pnt = 0;
            for (int i = 0; i < 10; i++)
                for (int j = 0; j < m[i]; j++)
                    data[pnt++] = exp[i][j];
            cout << "Iter " << dig << " : ";
            displayData();
        }
        cout << "Sorted Data: ";
        displayData();
    } else
        cout << "Invalid algorithm for this datatype\n";
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
    T pivot = data[high];
    int current = low - 1;
    for (int j = low; j < high; j++) {
        if (data[j] <= pivot)
            swap(data[++current], data[j]);
    }
    swap(data[current + 1], data[high]);
    return current + 1;
}

// Utility functions (TODO: Implement them)
template<typename T>
void SortingSystem<T>::displayData() {
    cout << "[";
    for (int i = 0; i < size; i++)
        cout << " " << data[i] << ", "[i == size - 1];
    cout << "]" << endl;
}

template<typename T>
void SortingSystem<T>::measureSortTime(void (SortingSystem::*sortFunc)()) {
    using namespace chrono;
    const time_point<system_clock> start = system_clock::now();
    (this->*sortFunc)();
    const time_point<system_clock> end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << fixed << setprecision(5) << "Sorting Time: " << duration.count() / 1000000.0 << "seconds" << endl;
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
                    measureSortTime(&SortingSystem<T>::insertionSort);
                    break;
                case 2:
                    measureSortTime(&SortingSystem<T>::selectionSort);
                    break;
                case 3:
                    measureSortTime(&SortingSystem<T>::bubbleSort);
                    break;
                case 4:
                    measureSortTime(&SortingSystem<T>::shellSort);
                    break;
                case 5:
                    measureSortTime(&SortingSystem<T>::mergeSort);
                    break;
                case 6:
                    measureSortTime(&SortingSystem<T>::quickSort);
                    break;
                case 7:
                    measureSortTime(&SortingSystem<T>::countSort);
                    break;
                case 8:
                    measureSortTime(&SortingSystem<T>::radixSort);
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
    while (cin >> type) {
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
    }
}
