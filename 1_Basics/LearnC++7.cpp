#include <bits/stdc++.h>
using namespace std;

int main() {
    // Example of a for loop
    /*
    for (int i = 1; i <= 10; i += 1) {
        cout << "pratt" << "\n";
    }
    // The variable 'i' is only accessible within the scope of the for loop.
    // Uncommenting the following line will cause an error:
    // cout << i;
    */

    // Example of a while loop
    /*
    int i = 1;
    while (i <= 5) {
        cout << "pratt" << endl;
        i += 1;
    }
    */

    // Example of a do-while loop
    // A do-while loop executes the code block at least once
    int i = 2;
    do {
        cout << "pratt" << endl;
        i += 1;
    } while (i <= 1);

    // Display the value of 'i' after the loop
    cout << "Final value of i: " << i << endl;

    return 0;
}