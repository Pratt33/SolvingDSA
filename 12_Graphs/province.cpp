#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adj_ls(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj_ls[i].push_back(j);
                    adj_ls[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj_ls, vis);
                cnt++;
            }
        }
        return cnt;
    }

    void dfs(int node, vector<vector<int>>& adj_ls, vector<int>& vis) {
        vis[node] = 1;

        for (auto it : adj_ls[node]) {
            if (!vis[it]) {
                dfs(it, adj_ls, vis);
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    int provinces = sol.findCircleNum(isConnected);
    cout << "Number of provinces: " << provinces << endl;

    return 0;
}