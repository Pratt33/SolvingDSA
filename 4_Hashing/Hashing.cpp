#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Precompute frequencies
    const int MAX_VALUE = 13;
    vector<int> hash(MAX_VALUE, 0);

    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    int q;
    cin >> q;

    while (q--) {
        int num;
        cin >> num;

        // Fetch and output frequency
        if (num >= 0 && num < MAX_VALUE) {
            cout << hash[num] << endl;
        } else {
            cout << 0 << endl; // Handle out-of-range queries
        }
    }

    return 0;
}