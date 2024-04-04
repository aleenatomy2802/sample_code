/**
 * The popularity of a sorting algorithm can depend on the context in which it is used, including factors like the size of the data set, the nature of the data, and the specific requirements for time and space efficiency. However, some sorting algorithms are widely recognized for their general utility and efficiency in a variety of scenarios. Among the most popular and frequently used sorting algorithms are:

1. **QuickSort**: Often chosen for its average-case efficiency, QuickSort is a divide-and-conquer algorithm that, on average, makes O(n log n) comparisons to sort n items. However, in the worst case, it can make O(n^2) comparisons, though this can be mitigated with careful implementation.

2. **MergeSort**: Also a divide-and-conquer algorithm, MergeSort guarantees O(n log n) time complexity in the worst case, making it highly predictable and reliable. It is stable and works well for large data sets, but it requires additional space proportional to the size of the data being sorted.

3. **HeapSort**: This algorithm uses a binary heap data structure to sort elements, achieving O(n log n) time complexity in the worst case. It does not require additional space (beyond what is needed for the heap), making it an in-place sort, though it is not stable.

4. **Insertion Sort**: While not as efficient for large data sets as the above algorithms (with O(n^2) time complexity in the worst case), Insertion Sort is simple, stable, and efficient for small or nearly sorted data sets. It is often used as part of more complex algorithms like IntroSort.

5. **Timsort**: A hybrid sorting algorithm derived from MergeSort and Insertion Sort, Timsort is designed to perform well on many kinds of real-world data. It is stable and adaptive, with O(n log n) worst-case performance. Timsort is the default sorting algorithm in Python's `sort()` function and Java's `Arrays.sort()` method for objects.

6. **Radix Sort**: Unlike comparison-based sorting algorithms, Radix Sort processes integer keys "digit" by digit, working from the least significant digit to the most significant. Its time complexity can be as low as O(nk) for n keys of k digits. It is efficient for fixed-length integer sorting and is stable but requires additional space.

7. **Bubble Sort**

8. **Selection Sort**

The choice of sorting algorithm depends on the specific requirements of the application, including considerations of time complexity, space complexity, stability (whether equal elements retain their original order), and whether the data is accessed sequentially or randomly. QuickSort and MergeSort are often cited as general-purpose sorting algorithms due to their efficiency and speed in various scenarios. Timsort, due to its adaptability and efficiency with real-world data, has also become a popular choice in programming languages' standard libraries.
*/ 
#include <vector>
using namespace std;


/*
1. **Quick Sort**:
   - Quick Sort is a divide-and-conquer algorithm.
   - It selects a pivot element from the array and partitions the other elements into two sub-arrays according to whether they are less than or greater than the pivot.
   - It then recursively sorts the sub-arrays.
*/
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
/*
- Time Complexity: Average case: O(n log n), Worst case: O(n^2).
- Space Complexity: O(log n).
- Use Case: Quick Sort is a popular choice for sorting large datasets, as it has good average-case performance. 
It's often used in applications where average-case performance matters more than worst-case performance, 
such as in sorting massive datasets in databases.
*/

/*
2. **Insertion Sort**:
   - Insertion Sort builds the final sorted array one element at a time.
   - It iterates through each element in the array, moving it backwards through the array until it's in its correct sorted position.
   - It repeats this process for each element until the entire array is sorted.
*/
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
/*
- Time Complexity: Average case: O(n^2), Worst case: O(n^2).
- Space Complexity: O(1).
- Use Case: Insertion Sort is efficient for sorting small datasets or nearly sorted datasets.
It's often used in scenarios where the input size is small or the list is almost sorted.
*/

/*
3. **Merge Sort**:
   - Merge Sort divides the array into two halves, sorts each half recursively, and then merges the sorted halves.
   - It continuously divides the array in half until it's left with single elements.
   - It then merges these single elements back together into sorted sub-arrays until the entire array is sorted.
*/
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
/*
- Time Complexity: O(n log n) in all cases.
- Space Complexity: O(n).
- Use Case: Merge Sort is preferred for sorting linked lists and arrays with large data sets, as it guarantees O(n log n) time complexity in all cases. 
It's suitable for external sorting where data is too large to fit into memory.
*/

/*
4. **Heap Sort**:
   - Heap Sort is based on the heap data structure, specifically the binary heap.
   - It first builds a heap from the input array.
   - It repeatedly extracts the maximum (for max-heap) element from the heap and puts it at the end of the array.
   - It then reduces the size of the heap and heapifies the heap to maintain the heap property.

*/
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

/*
- Time Complexity: O(n log n) in all cases.
- Space Complexity: O(1).
- Use Case: Heap Sort is used when a guaranteed O(n log n) performance is required. 
It's often used in scenarios where memory usage needs to be optimized, as it has a space complexity of O(1).
*/

