#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // STEP 1: Build adjacency list
        // We need to represent the graph where edges point from prerequisite to course
        // If course A is prerequisite for course B, then A -> B
        vector<vector<int>> adj(numCourses);
        
        for(auto& pre : prerequisites) {
            int u = pre[0];  // Course that needs prerequisite
            int v = pre[1];  // Prerequisite course
            
            // IMPORTANT: We add edge from prerequisite TO course (v -> u)
            // This means: after completing course v, we can take course u
            adj[v].push_back(u);
        }
        
        // STEP 2: Calculate indegree for each course
        // Indegree = number of prerequisites a course has
        vector<int> inDeg(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++) {
            // For each course i, look at all courses it enables
            for(int j = 0; j < adj[i].size(); j++) {
                int enabledCourse = adj[i][j];
                // Increment indegree of the enabled course
                inDeg[enabledCourse]++;
            }
        }
        
        // STEP 3: Find all courses with no prerequisites (indegree = 0)
        // These courses can be taken immediately
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDeg[i] == 0) {
                q.push(i);
            }
        }
        
        // STEP 4: Process courses using Kahn's algorithm (Topological Sort)
        // We'll keep track of courses we can complete
        vector<int> completedCourses;
        
        while(!q.empty()) {
            // Take a course with no remaining prerequisites
            int currentCourse = q.front();
            q.pop();
            
            // Mark this course as completed
            completedCourses.push_back(currentCourse);
            
            // Now that we've completed currentCourse, check all courses it enables
            for(int j = 0; j < adj[currentCourse].size(); j++) {
                int enabledCourse = adj[currentCourse][j];
                
                // Reduce the prerequisite count for the enabled course
                inDeg[enabledCourse]--;
                
                // If this enabled course now has no remaining prerequisites,
                // we can take it next
                if(inDeg[enabledCourse] == 0) {
                    q.push(enabledCourse);
                }
            }
        }
        
        // STEP 5: Check if we can complete all courses
        // If we processed all courses, there's no cycle
        // If we couldn't process some courses, there's a cycle (impossible to complete)
        return completedCourses.size() == numCourses;
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec, const string& name) {
    cout << name << ": [";
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if(i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Helper function to print adjacency list
void printAdjList(const vector<vector<int>>& adj) {
    cout << "Adjacency List:" << endl;
    for(int i = 0; i < adj.size(); i++) {
        cout << "Course " << i << " -> ";
        if(adj[i].empty()) {
            cout << "[]";
        } else {
            cout << "[";
            for(int j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j];
                if(j < adj[i].size() - 1) cout << ", ";
            }
            cout << "]";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;
    
    // Test Case 1: Possible to complete all courses
    cout << "=== TEST CASE 1 ===" << endl;
    cout << "numCourses = 4" << endl;
    cout << "prerequisites = [[1,0], [2,0], [3,1], [3,2]]" << endl;
    cout << "Meaning:" << endl;
    cout << "- Course 1 requires course 0" << endl;
    cout << "- Course 2 requires course 0" << endl;
    cout << "- Course 3 requires course 1" << endl;
    cout << "- Course 3 requires course 2" << endl;
    cout << endl;
    
    vector<vector<int>> prerequisites1 = {{1,0}, {2,0}, {3,1}, {3,2}};
    bool result1 = solution.canFinish(4, prerequisites1);
    cout << "Can finish all courses? " << (result1 ? "YES" : "NO") << endl;
    cout << "Expected: YES" << endl;
    cout << endl;
    
    // Test Case 2: Impossible due to cycle
    cout << "=== TEST CASE 2 ===" << endl;
    cout << "numCourses = 2" << endl;
    cout << "prerequisites = [[1,0], [0,1]]" << endl;
    cout << "Meaning:" << endl;
    cout << "- Course 1 requires course 0" << endl;
    cout << "- Course 0 requires course 1" << endl;
    cout << "This creates a cycle!" << endl;
    cout << endl;
    
    vector<vector<int>> prerequisites2 = {{1,0}, {0,1}};
    bool result2 = solution.canFinish(2, prerequisites2);
    cout << "Can finish all courses? " << (result2 ? "YES" : "NO") << endl;
    cout << "Expected: NO" << endl;
    cout << endl;
    
    // Test Case 3: No prerequisites
    cout << "=== TEST CASE 3 ===" << endl;
    cout << "numCourses = 3" << endl;
    cout << "prerequisites = []" << endl;
    cout << "Meaning: No prerequisites for any course" << endl;
    cout << endl;
    
    vector<vector<int>> prerequisites3 = {};
    bool result3 = solution.canFinish(3, prerequisites3);
    cout << "Can finish all courses? " << (result3 ? "YES" : "NO") << endl;
    cout << "Expected: YES" << endl;
    cout << endl;
    
    // Detailed walkthrough for Test Case 1
    cout << "=== DETAILED WALKTHROUGH FOR TEST CASE 1 ===" << endl;
    
    // Manually build adjacency list to show
    vector<vector<int>> adj(4);
    for(auto& pre : prerequisites1) {
        int u = pre[0], v = pre[1];
        adj[v].push_back(u);
    }
    printAdjList(adj);
    
    // Calculate and show indegrees
    vector<int> inDeg(4, 0);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            inDeg[adj[i][j]]++;
        }
    }
    printVector(inDeg, "Initial Indegrees");
    
    cout << endl;
    cout << "Processing Order:" << endl;
    cout << "1. Start with course 0 (indegree = 0)" << endl;
    cout << "2. After course 0, courses 1 and 2 become available" << endl;
    cout << "3. After courses 1 and 2, course 3 becomes available" << endl;
    cout << "4. All courses processed successfully!" << endl;
    
    return 0;
}