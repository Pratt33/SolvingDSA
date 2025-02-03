#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Input string
    string s;
    cin >> s;
    int n = s.size();

    // Frequency array for storing the count of each character
    vector<int> charFrequency(26, 0);
    for (int i = 0; i < n; i++) {
        charFrequency[s[i] - 'a']++;
    }

    // Process queries
    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        // Output the frequency of the given character
        cout << charFrequency[c - 'a'] << endl;
    }

    return 0;
}