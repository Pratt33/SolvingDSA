#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Version 1: Using vector and find (no memoization)
// Brute Force
class SolutionVector {
public:
    bool canCross(vector<int>& stones) {
        if (stones.size() < 2 || stones[1] != 1) return false;
        return dfs(stones, 1, 1);
    }

    bool dfs(vector<int>& stones, int position, int lastJump){
        if (position == stones.back()) return true;

        for (int jump = lastJump - 1; jump <= lastJump + 1; jump++) {
            if (jump <= 0) continue;

            int nextPos = position + jump;

            if (find(stones.begin(), stones.end(), nextPos) != stones.end()) {
                if (dfs(stones, nextPos, jump)) return true;
            }
        }
        return false;
    }
};

// Version 2: Using unordered_set for fast lookup (no memoization)
// Time Optimization
class SolutionSet {
public:
    bool canCross(vector<int>& stones) {
        if (stones.size() < 2 || stones[1] != 1) return false;
        unordered_set<int> stoneSet(stones.begin(), stones.end());
        int target = stones.back();
        return dfs(stoneSet, 1, 1, target);
    }

    bool dfs(unordered_set<int>& stoneSet, int position, int lastJump, int target) {
        if (position == target) return true;

        for (int jump = lastJump - 1; jump <= lastJump + 1; jump++) {
            if (jump <= 0) continue;

            int nextPos = position + jump;

            if (stoneSet.count(nextPos)) {
                if (dfs(stoneSet, nextPos, jump, target)) return true;
            }
        }
        return false;
    }
};

// Version 3: Using unordered_set and memoization (optimal)
class SolutionMemo {
public:
    bool canCross(vector<int>& stones) {
        if (stones.size() < 2 || stones[1] != 1) return false;
        unordered_set<int> stoneSet(stones.begin(), stones.end());
        int target = stones.back();
        unordered_map<int, unordered_set<int>> memo;
        return dfs(stoneSet, 1, 1, target, memo);
    }

    bool dfs(unordered_set<int>& stoneSet, int position, int lastJump, int target,
             unordered_map<int, unordered_set<int>>& memo) {
        if (position == target) return true;
        if (memo[position].count(lastJump)) return false;

        for (int jump = lastJump - 1; jump <= lastJump + 1; jump++) {
            if (jump <= 0) continue;
            int nextPos = position + jump;
            if (stoneSet.count(nextPos)) {
                if (dfs(stoneSet, nextPos, jump, target, memo)) {
                    return true;
                }
            }
        }
        memo[position].insert(lastJump);
        return false;
    }
};

int main() {
    vector<int> stones = {0,1,3,5,6,8,12,17};

    SolutionVector solVec;
    SolutionSet solSet;
    SolutionMemo solMemo;

    cout << "[SolutionVector] " << (solVec.canCross(stones) ? "Can cross the river!" : "Cannot cross the river.") << endl;
    cout << "[SolutionSet]    " << (solSet.canCross(stones) ? "Can cross the river!" : "Cannot cross the river.") << endl;
    cout << "[SolutionMemo]   " << (solMemo.canCross(stones) ? "Can cross the river!" : "Cannot cross the river.") << endl;

    return 0;
}