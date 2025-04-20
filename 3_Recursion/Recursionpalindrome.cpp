#include <bits/stdc++.h>
using namespace std;

// Recursive utility function to check if the string is a palindrome
bool isPalindromeUtil(string s, int l, int r) {
    if (l >= r) return true; // Base case: reached the middle
    if (s[l] != s[r]) return false; // Characters don't match
    return isPalindromeUtil(s, l + 1, r - 1); // Recursive case
}

// Function to check if a string is a palindrome
bool isPalindrome(string s) {
    if (s.empty()) return true; // An empty string is a palindrome
    return isPalindromeUtil(s, 0, s.size() - 1);
}

int main() {
    string s = "A man, a plan, a canal: Panama";
    if (isPalindrome(s)) {
        cout << "\"" << s << "\" is a palindrome.\n";
    } else {
        cout << "\"" << s << "\" is not a palindrome.\n";
    }
    return 0;
}