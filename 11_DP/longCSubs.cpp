#include <bits/stdc++.h>
using namespace std;

string findLCS(int n, int m, string &s1, string &s2) {
    // Step 1: Build DP table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Step 2: Trace back to get LCS string
    int i = n, j = m;
    string lcs = "";
    while(i > 0 && j > 0){
        if(s1[i - 1] == s2[j - 1]){
            lcs += s1[i - 1]; // Add character to LCS
            i--; j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string s1 = "abcde";
    string s2 = "ace";
    int n = s1.size();
    int m = s2.size();

    string lcs = findLCS(n, m, s1, s2);
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}