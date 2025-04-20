#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void print() {
    if (cnt == 3) return;  // Check if cnt has reached 3
    cout << cnt << endl;   // Print the current value of cnt
    cnt++;                 // Increment cnt
    print();              // Recursive call
}

int main() {
    print();  // Call the print function
    return 0;
}