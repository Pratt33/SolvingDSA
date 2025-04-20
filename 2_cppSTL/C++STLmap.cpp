#include <bits/stdc++.h>
using namespace std;

void exploreMap() {
    map<int, int> mpp;
    // Operations in map are O(log(n)).
    // A map stores data in key-value pairs, where both key and value can be of any datatype.

    map<pair<int, int>, int> mp; // Key is a pair of 2 ints, and the value is a single int.

    // A map stores unique keys in sorted order.
    mpp[1] = 2;          // {1, 2}
    mpp.insert({3, 1});  // {{1, 2}, {3, 1}}
    mpp.emplace(2, 3);   // {{1, 2}, {2, 3}, {3, 1}}

    mp[{2, 4}] = 10; // Key: {2, 4}, Value: 10

    // Iterating over the map
    for (auto it : mpp) {
        cout << it.first << " " << it.second << endl;
    }

    // Accessing elements
    cout << "Value at key 2: " << mpp[2] << endl; // Outputs 3
    cout << "Value at key 5: " << mpp[5] << endl; // Outputs 0 (default value for int)

    // Finding an element
    auto it = mpp.find(3); // Returns an iterator to key 3, or mpp.end() if not found
    if (it != mpp.end()) {
        cout << "Value at key 3: " << it->second << endl;
    } else {
        cout << "Key 3 not found\n";
    }

    // lower_bound and upper_bound work in the same fashion as in set
    auto lb = mpp.lower_bound(2); // First element >= 2
    auto ub = mpp.upper_bound(2); // First element > 2

    if (lb != mpp.end()) {
        cout << "Lower bound: " << lb->first << " " << lb->second << endl;
    } else {
        cout << "Lower bound not found\n";
    }

    if (ub != mpp.end()) {
        cout << "Upper bound: " << ub->first << " " << ub->second << endl;
    } else {
        cout << "Upper bound not found\n";
    }
}

void exploreMultimap() {
    // A multimap can store duplicate keys, but all keys and values are stored in sorted order.
    multimap<int, int> mpp;

    mpp.insert({1, 2}); // {{1, 2}}
    mpp.insert({1, 3}); // {{1, 2}, {1, 3}}

    // Iterating over the multimap
    for (auto it : mpp) {
        cout << it.first << " " << it.second << endl;
    }

    // Note: mpp[key] cannot be used in multimap since keys can have multiple values.
}

void exploreUnorderedMap() {
    // An unordered_map provides average O(1) complexity for operations.
    // In rare worst cases, it may degrade to O(n).

    unordered_map<int, int> umpp;

    // Insert elements
    umpp[1] = 2;
    umpp[3] = 4;
    umpp[2] = 5;

    // Iterating over the unordered_map
    cout << "Unordered map elements:\n";
    for (auto it : umpp) {
        cout << it.first << " " << it.second << endl;
    }

    // Accessing elements
    cout << "Value at key 2: " << umpp[2] << endl;

    // Finding an element
    auto it = umpp.find(3); // Returns an iterator to key 3, or umpp.end() if not found
    if (it != umpp.end()) {
        cout << "Value at key 3: " << it->second << endl;
    } else {
        cout << "Key 3 not found\n";
    }

    // Note: Keys are unique, but elements are not stored in sorted order.
    // lower_bound and upper_bound are not available in unordered_map.
}

int main() {
    cout << "Exploring map:\n";
    exploreMap();

    cout << "\nExploring multimap:\n";
    exploreMultimap();

    cout << "\nExploring unordered_map:\n";
    exploreUnorderedMap();

    return 0;
}