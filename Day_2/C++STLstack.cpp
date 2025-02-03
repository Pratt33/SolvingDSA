#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Demonstrates stack (LIFO) operations
void exploreStack() {
    stack<int> st;
    st.push(2); st.push(3); st.push(4); st.emplace(5); // Stack: {5, 4, 3, 2}

    cout << "Stack Top: " << st.top() << endl; // 5
    st.pop(); // Removes 5, Stack: {4, 3, 2}
    cout << "After Pop, Stack Top: " << st.top() << endl; // 4
}

// Demonstrates queue (FIFO) operations
void exploreQueue() {
    queue<int> q;
    q.push(1); q.push(2); q.emplace(3); // Queue: {1, 2, 3}
    q.back() += 5; // Queue becomes {1, 2, 8}

    cout << "Queue Front: " << q.front() << ", Queue Back: " << q.back() << endl; // 1, 8
    q.pop(); // Removes 1, Queue: {2, 8}
    cout << "After Pop, Queue Front: " << q.front() << endl; // 2
}

int main() {
    exploreStack();
    exploreQueue();
    return 0;
}