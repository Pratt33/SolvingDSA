#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

// Function to explore operations on std::set
//every operation in set happens in log(n) time complexity
void exploreSet() {
    set<int> st;

    // Insert elements (unique and sorted automatically)
    st.insert(1); // {1}
    st.emplace(2); // {1, 2}
    st.insert(4); // {1, 2, 4}
    st.insert(3); // {1, 2, 3, 4}

    // Find element in the set
    auto it = st.find(3); // Returns iterator to 3, or st.end() if not found
    if (it != st.end()) 
        cout << "Element 3 found\n";

    // Erase element by iterator or value
    st.erase(it); // Removes 3 using iterator
    st.erase(4); // Removes 4 by value

    // Count: Always 0 or 1 (since elements are unique)
    cout << "Count of 2: " << st.count(2) << endl;

    // Lower and upper bounds
    auto lb = st.lower_bound(2); // First element >= 2
    auto ub = st.upper_bound(2); // First element > 2

    if (lb != st.end()) 
        cout << "Lower bound: " << *lb << endl;
    else 
        cout << "Lower bound not found\n";

    if (ub != st.end()) 
        cout << "Upper bound: " << *ub << endl;
    else 
        cout << "Upper bound not found\n";
}

// Function to explore operations on std::multiset
void exploreMultiset() {
    multiset<int> ml;

    // Insert elements (allows duplicates, sorted automatically)
    ml.insert(1); // {1}
    ml.emplace(1); // {1, 1}
    ml.insert(1); // {1, 1, 1}

    // Erase all occurrences of an element
    ml.erase(1); // {}

    // Reinsert elements for demonstration
    ml.insert(1);
    ml.insert(2);
    ml.insert(1);

    // Erase a single occurrence using iterator
    auto it = ml.find(1); // Finds first occurrence of 1
    if (it != ml.end())
        ml.erase(it); // Erases one occurrence of 1

    // Erase a range of elements
    // Using std::next to demonstrate range-based erase
    ml.insert(1); // Adding some elements back for range erase
    ml.erase(ml.find(1), next(ml.find(1), 2)); // Erases a range of 2 elements

    // Print remaining elements
    cout << "Remaining elements in multiset: ";
    for (int x : ml) 
        cout << x << " ";
    cout << endl;
}

// Function to explore operations on std::unordered_set
void exploreUnorderedSet() {
    unordered_set<int> uns;

    // Insert elements (unique but unordered)
    uns.insert(3);
    uns.insert(1);
    uns.insert(2);

    // Print elements (order is not guaranteed)
    cout << "Unordered set elements: ";
    for (int x : uns) 
        cout << x << " ";
    cout << endl;

    // Find and erase elements
    auto it = uns.find(2); // Finds 2 if it exists
    if (it != uns.end()) {
        cout << "Element 2 found and erased\n";
        uns.erase(it);
    }

    // Print elements after erase
    cout << "Unordered set elements after erase: ";
    for (int x : uns) 
        cout << x << " ";
    cout << endl;

    // Important Notes:
    // 1. All operations in std::unordered_set generally take O(1) time.
    // 2. In the worst case, operations might degrade to O(n).
    // 3. Unlike std::set, lower_bound() and upper_bound() are not available.
}

int main() {
    cout << "Exploring std::set:\n";
    exploreSet();

    cout << "\nExploring std::multiset:\n";
    exploreMultiset();

    cout << "\nExploring std::unordered_set:\n";
    exploreUnorderedSet();

    return 0;
}