#include <vector>
#include <utility> // for pair
#include <iostream> // for cout
using namespace std;

int findCeil(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int result = -1; // Initialize to -1 in case no ceiling exists

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            result = arr[mid]; // Update result to the current ceiling
            high = mid - 1; // Search in the left half for a smaller ceiling
        } else {
            low = mid + 1; // Search in the right half
        }
    }

    return result;
}

int findFloor(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int result = -1; // Initialize to -1 in case no floor exists

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x) {
            result = arr[mid]; // Update result to the current floor
            low = mid + 1; // Search in the right half for a larger floor
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return result;
}

pair<int, int> getFloorAndCeil(vector<int>& a, int n, int x) {
    int f = findFloor(a, n, x);
    int c = findCeil(a, n, x);
    return {f, c};
}

int main() {
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int n = arr.size();
    int x = 5;

    pair<int, int> result = getFloorAndCeil(arr, n, x);
    cout << "Floor: " << result.first << ", Ceil: " << result.second << endl;

    return 0;
}