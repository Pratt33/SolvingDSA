#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        return f(word1.size()-1, word2.size()-1, word1, word2, dp);
    }

    int f(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if(i < 0) return j + 1; // Need to insert all remaining chars from word2
        if(j < 0) return i + 1; // Need to delete all remaining chars from word1

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j])
            return dp[i][j] = f(i - 1, j - 1, word1, word2, dp);

        int oI = 1 + f(i, j - 1, word1, word2, dp);     // Insert
        int oD = 1 + f(i - 1, j, word1, word2, dp);     // Delete
        int oR = 1 + f(i - 1, j - 1, word1, word2, dp); // Replace

        return dp[i][j] = min({oI, oD, oR});
    }
};

int main() {
    Solution sol;

    string word1 = "horse";
    string word2 = "ros";

    int operations = sol.minDistance(word1, word2);
    cout << "Minimum Edit Distance: " << operations << endl;

    return 0;
}