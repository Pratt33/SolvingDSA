#include <bits/stdc++.h>
using namespace std;

//Algorithm	        Best	Average	Worst	Space
//Insertion Sort	O(n)	O(n²)	O(n²)	O(1)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {  // Start from 1, as the first element is already "sorted"
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {  // Shift elements to the right
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  // Place the key at the correct position
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];  
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertionSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}