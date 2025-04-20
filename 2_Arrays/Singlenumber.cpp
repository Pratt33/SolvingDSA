#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    for (auto it : freq) {
        if (it.second == 1) return it.first;
    }
    return -1;  // Should never reach here based on problem constraints
}

int main() {
    int n;
    cin >> n;  // Corrected input syntax

    vector<int> arr(n);  // Use vector instead of a raw array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Corrected input syntax
    }

    int result = singleNumber(arr);
    cout << "The single number is: " << result << endl;  // Print the result

    return 0;
}