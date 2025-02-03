#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;

int main() {
    // Declare a variable to store the user's age
    int age;

    // Prompt the user to enter their age
    cout << "Enter your age: ";
    cin >> age; // Take the input and store it in the variable 'age'

    // Check if the user is an adult (18 or older)
    if (age >= 18) {
        cout << "\nYou are an adult."; // Message for adults
    } else {
        cout << "\nYou are less than 18."; // Message for those under 18
    }

    // Indicate that the program ended successfully
    return 0;
}