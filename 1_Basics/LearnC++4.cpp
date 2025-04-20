#include <bits/stdc++.h>
using namespace std;

int main() {
    // Prompt the user to enter their marks
    cout << "Enter your marks: \n";
    int marks;
    cin >> marks;

    // Check if the entered marks are valid
    if (marks <= 100) {
        // Grade calculation based on marks
        if (marks < 25) {
            cout << "Grade: F"; // Marks less than 25
        } else if (marks < 45) {
            cout << "Grade: E"; // Marks between 25 and 44
        } else if (marks < 50) {
            cout << "Grade: D"; // Marks between 45 and 49
        } else if (marks < 60) {
            cout << "Grade: C"; // Marks between 50 and 59
        } else if (marks < 80) {
            cout << "Grade: B"; // Marks between 60 and 79
        } else {
            cout << "Grade: A"; // Marks 80 and above
        }
    } else {
        // Invalid marks entered
        cout << "Invalid marks entered. Please enter marks between 0 and 100.";
    }

    return 0;
}