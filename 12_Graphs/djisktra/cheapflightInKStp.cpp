#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<vector<pair<int, int>>> adj(n);
        for (auto &flight:flights){
            int u=flight[0], v=flight[1], pr=flight[2];
            adj[u].push_back({v, pr});
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, src, 0});

        while(!pq.empty()){
            auto [cst, ciy, stp]=pq.top();
            pq.pop();

            if(ciy==dst) return cst;

            if(stp > k) continue;

            for(auto [neighbor, pr] : adj[ciy]){
                int ncst = cst + pr;
                pq.push({ncst, neighbor, stp + 1});
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    
    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };
    int src = 0, dst = 2, k = 1;

    int result = sol.findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest price: " << result << endl;

    return 0;
}