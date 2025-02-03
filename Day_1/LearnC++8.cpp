#include <bits/stdc++.h>
using namespace std;

// Function to print a greeting with the given name
void printName(string name) {
    cout << "Hi " << name << endl;
}

// Function to calculate and return the sum of two numbers
int sum(int num1, int num2) {
    return num1 + num2;
}

int main() {
    // Functions help modularize the code
    // Benefits of using functions:
    // - Increased readability
    // - Avoid redundancy by reusing code
    // - Easier to debug and maintain

    // Example 1: Using the printName function
    /*
    string name;
    cin >> name;               // Input the name
    printName(name);           // Call the function to print the greeting
    */

    // Example 2: Using the sum function
    int num1, num2;
    cin >> num1 >> num2;        // Input two numbers
    int res = sum(num1, num2);  // Call the function to calculate the sum
    cout << res << endl;        // Output the result

    return 0;
}