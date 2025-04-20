#include <bits/stdc++.h>
using namespace std;

// Function to demonstrate pass-by-reference
void doSomething(string &s) {
    // Modify the first character of the string
    s[0] = 't';
    cout << "Inside function: " << s << endl;
}

int main() {
    // Input a string
    string s;
    cin >> s;

    // Call the function to modify the string
    doSomething(s);

    // Output the modified string in main
    cout << "In main: " << s << endl;

    return 0;
}

/*
// Uncomment this block for a demonstration of pass-by-value
void doSomething(int num) {
    cout << "Initial value: " << num << endl;
    num += 5;
    cout << "After adding 5: " << num << endl;
    num += 5;
    cout << "After adding another 5: " << num << endl;
}

int main() {
    // Demonstrate pass-by-value (operation on a copy, not the original variable)
    int num = 10;
    doSomething(num);
    cout << "In main: " << num << endl;
    return 0;
}
*/

/* Note:
 * Arrays in C++ are always passed by reference to functions, 
 * so there is no need to explicitly attach the '&' sign 
 * when passing them as arguments.
 */