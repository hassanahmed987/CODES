#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
	//make sizes for temp arr
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int L[n1];
    int R[n2];
//make temp array for left and right
    for (int i = 0; i < n1; i++) {
        L[i] = arr[start + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    // merging thing 
    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
// any remaining would be put as it is
    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergesort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        mergesort(arr, start, mid);     // left
        mergesort(arr, mid + 1, end);   // right

        merge(arr, start, mid, end);    // merge
    }
}

