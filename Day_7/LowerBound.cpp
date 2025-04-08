#include <iostream>
#include <algorithm> // for lower_bound
#include <vector>

int main() {
    std::vector<int> toys = {2, 4, 6, 8, 10};
    
    // Find the first toy not smaller than 5
    auto it = std::lower_bound(toys.begin(), toys.end(), 7);
    
    if (it != toys.end()) {
        std::cout << "Found: " << *it << std::endl; // Output: 6
    } else {
        std::cout << "Nothing found!" << std::endl;
    }
    
    return 0;
}