#include <bits/stdc++.h>
using namespace std;

// Function to find the majority element using Boyer-Moore Voting Algorithm
int Boyermoorevote(int arr[], int n) {
    int cnt = 0; // Counter to keep track of the current candidate's lead
    int el = 0;  // Variable to store the potential majority element

    // Step 1: Find the potential majority element
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            // If the counter is 0, set the current element as the new candidate
            el = arr[i];
            cnt = 1;
        } else if (el == arr[i]) {
            // If the current element matches the candidate, increment the counter
            cnt++;
        } else {
            // If the current element is different, decrement the counter
            cnt--;
        }
    }

    // Step 2: Verify if the candidate is indeed the majority element
    int verfcnt = 0; // Counter to count occurrences of the candidate
    for (int i = 0; i < n; i++) {
        if (arr[i] == el) {
            verfcnt++; // Increment the counter if the current element matches the candidate
        }
        // Early exit: If the count exceeds n/2, return the candidate immediately
        if (verfcnt > (n / 2)) {
            return el;
        }
    }

    // If no majority element is found, return -1
    return -1;
}

int main() {
    int n;
    cin >> n; // Input the size of the array

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input the elements of the array
    }

    // Call the Boyermoorevote function to find the majority element
    int result = Boyermoorevote(arr, n);

    // Output the result
    if (result != -1) {
        cout << "Majority Element is: " << result << endl;
    } else {
        cout << "No Majority Element" << endl;
    }

    return 0;
}