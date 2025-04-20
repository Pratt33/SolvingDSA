#include <bits/stdc++.h>
using namespace std;

int main() {
    // Uncomment and use this block for a 1D array demonstration:
    /*
    // 1D Array Example
    int arr[5]; // Declare an array of size 5
    cout << "Enter 5 elements for the array:\n";
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];

    // Modify the 3rd element (index 2)
    arr[2] += 10;

    // Print the updated 3rd element
    cout << "Updated value of arr[2]: " << arr[2] << endl;
    return 0;
    */

    // Uncomment and use this block for a 2D array demonstration:
    /*
    // 2D Array Example
    int arr[3][5]; // Declare a 2D array with 3 rows and 5 columns

    // Assign a value to a specific element
    arr[1][3] = 56;

    // Print the value of the element at row 1, column 3
    cout << "Value at arr[1][3]: " << arr[1][3] << endl;
    */

    // String Example
    string s = "pratt"; // Declare and initialize a string
    int len = s.size(); // Get the length of the string

    // Modify the last character of the string
    s[len - 1] = 'z';

    // Print the updated string and its last character
    cout << "Updated string: " << s << "\n";
    cout << "Last character of the updated string: " << s[len - 1] << endl;

    return 0;
}