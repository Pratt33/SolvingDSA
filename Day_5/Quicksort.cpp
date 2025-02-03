#include <bits/stdc++.h>
using namespace std;
//                  Best        Avg     Worst   Space
//Quick Sort	O(n log n)	O(n log n)	O(n²)	O(log n)
int pivfind(int arr[], int low, int high) {
    int pivot = arr[low];  // Choosing the first element as the pivot
    int i = low + 1, j = high;

    while (i <= j) {
        while (i <= j && arr[i] <= pivot) i++;
        while (i <= j && arr[j] > pivot) j--;
        if (i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]); // Place pivot in the correct position
    return j;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int piv = pivfind(arr, low, high);
        quicksort(arr, low, piv - 1);
        quicksort(arr, piv + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quicksort(arr.data(), 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
