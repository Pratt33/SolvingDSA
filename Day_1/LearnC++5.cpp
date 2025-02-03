#include <bits/stdc++.h>
using namespace std;

int main() {
    int day;

    // Prompt the user to enter a day number
    cout << "Enter the day number (1-7): \n";
    cin >> day;

    // Determine the day of the week using a switch statement
    switch (day) {
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        case 6:
            cout << "Saturday";
            break;
        case 7:
            cout << "Sunday";
            break;
        default:
            // Handle invalid input
            cout << "Invalid day number. Please enter a number between 1 and 7.";
    }

    return 0;
}