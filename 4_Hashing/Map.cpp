#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    // Unlike hashing, where we store all possible keys regardless of whether they are used,
    // a map only stores the keys that are explicitly added to it. This helps save space.

    // Input the size of the array
    int n;
    cin >> n;
    vector<int> arr(n);

    // Read the array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Pre-compute frequencies using a map
    // The map will store each unique number from the array as a key
    // and its frequency (count of occurrences) as the value.
    map<int, int> frequencyMap;
    for (int i = 0; i < n; i++) {
        frequencyMap[arr[i]]++;
    }

    // Process queries
    int q;
    cin >> q;
    while (q--) {
        int num;
        cin >> num;

        // Output the frequency of the queried number
        // If the number does not exist in the map, the frequency will be 0 by default.
        cout << frequencyMap[num] << endl;
    }

    /* 
    // Using an unordered_map
    // An unordered_map can be used instead of a map to improve performance.
    // While a map stores keys in sorted order (logarithmic time complexity for operations),
    // an unordered_map stores keys in no specific order and provides average constant time complexity for insertions and lookups.
    // However, the unordered_map may have higher overhead in terms of memory usage.

    unordered_map<int, int> frequencyMap;
    for (int i = 0; i < n; i++) {
        frequencyMap[arr[i]]++;
    }
    */

    // One important consideration:
    // In rare cases, the worst-case time complexity can occur in hashing due to collisions.
    // Hashing typically uses a division method to compute the hash index.

    // Example:
    // Suppose the input elements are: 12, 24, 38, 18, 28, 18
    // If we take `mod` as the hash function (e.g., value % some_number), the hash array might look like this:
    // For mod 10: indices become 2, 4, 8, 8, 8, 8
    // The count would be:
    // index 2 -> 1 element (12)
    // index 4 -> 1 element (24)
    // index 8 -> 4 elements (18 -> 18 -> 28 -> 38)

    // Problem of collisions:
    // If multiple elements map to the same index (e.g., mod 8 in this case), the corresponding hash bucket becomes crowded.
    // Searching and counting frequencies then become inefficient, as we need to traverse the entire bucket.

    return 0;
}