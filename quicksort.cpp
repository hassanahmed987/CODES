#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int pivot = arr[s];
    int count = 0; // counting how many elements before the pivot

    // counting how many elements are smaller or equal to pivot
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    int pivotindex = s + count; // placing pivot at the right place
    swap(arr[pivotindex], arr[s]);

    int i = s, j = e;
    while (i < pivotindex && j > pivotindex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotindex && j > pivotindex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotindex;
}

void quicksort(int arr[], int s, int e) {
    if (s >= e) {
        return;
    }
    int p = partition(arr, s, e);
    quicksort(arr, s, p - 1); // left
    quicksort(arr, p + 1, e); // right
}
