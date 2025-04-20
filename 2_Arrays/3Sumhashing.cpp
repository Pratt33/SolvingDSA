#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> findTriplets(vector<int> &arr, int n, int K) {
    set<vector<int>> uniqueTriplets;

    for (int i = 0; i < n; i++) {
        unordered_set<int> seen;
        for (int j = i + 1; j < n; j++) {
            int third = K - (arr[i] + arr[j]);
            if (seen.count(third)) {
                vector<int> triplet = {arr[i], arr[j], third};
                sort(triplet.begin(), triplet.end());
                uniqueTriplets.insert(triplet);
            }
            seen.insert(arr[j]);
        }
    }

    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}

int main() {
    vector<int> arr = {1, 2, -3, 4, -2, -1, 0, 3};
    int K = 0;
    int n = arr.size();

    vector<vector<int>> triplets = findTriplets(arr, n, K);

    cout << "Triplets summing to " << K << ":\n";
    for (const auto &triplet : triplets) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}