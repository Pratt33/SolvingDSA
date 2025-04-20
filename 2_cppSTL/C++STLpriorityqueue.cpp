#include <iostream>
#include <queue>
using namespace std;
//time complexity push, pop-->log(n), top--> o(1)
// Demonstrates max-heap operations
void exploreMaxHeap() {
    priority_queue<int> pq; // Max-heap
    pq.push(5);
    pq.push(10);
    pq.push(7);
    pq.emplace(15); // {15, 10, 7, 5}
    
    cout << "Max-Heap Top: " << pq.top() << endl; // 15
    pq.pop(); // Removes 15
    cout << "After Pop, Max-Heap Top: " << pq.top() << endl; // 10
}

// Demonstrates min-heap operations
void exploreMinHeap() {
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
    pq.push(5);
    pq.push(10);
    pq.push(7);
    pq.emplace(15); // {5, 7, 10, 15}
    
    cout << "Min-Heap Top: " << pq.top() << endl; // 5
    pq.pop(); // Removes 5
    cout << "After Pop, Min-Heap Top: " << pq.top() << endl; // 7
}

int main() {
    cout << "Exploring Max-Heap:" << endl;
    exploreMaxHeap();
    
    cout << "\nExploring Min-Heap:" << endl;
    exploreMinHeap();
    
    return 0;
}