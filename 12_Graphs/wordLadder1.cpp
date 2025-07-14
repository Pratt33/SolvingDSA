#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        wordList.push_back(beginWord);
        int n = wordList.size();

        // Build adjacency list
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isOneCharDiff(wordList[i], wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // BFS for shortest path
        vector<bool> vis(n, false);
        queue<pair<int, int>> q;

        int start = n - 1; // beginWord is at the end
        q.push({start, 1});
        vis[start] = true;

        while (!q.empty()) {
            auto [node, steps] = q.front();
            q.pop();

            if (wordList[node] == endWord) return steps;

            for (int neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = true;
                    q.push({neighbor, steps + 1});
                }
            }
        }

        return 0;
    }

    bool isOneCharDiff(string& a, string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) diff++;
            if (diff > 1) return false;
        }
        return diff == 1;
    }
};