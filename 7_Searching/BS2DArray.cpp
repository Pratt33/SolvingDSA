#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, col = m - 1;
        
        while (row < n && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                row++;
            } else {
                col--;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    
    // Test case 1: Target is present in the matrix
    vector<vector<int>> matrix1 = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    int target1 = 5;
    cout << "Test case 1 (Target 5): " << (sol.searchMatrix(matrix1, target1) ? "true" : "false") << endl; // Expected: true

    // Test case 2: Target is not present in the matrix
    int target2 = 15;
    cout << "Test case 2 (Target 15): " << (sol.searchMatrix(matrix1, target2) ? "true" : "false") << endl; // Expected: false

    // Test case 3: Empty matrix
    vector<vector<int>> matrix2;
    int target3 = 1;
    cout << "Test case 3 (Empty matrix): " << (sol.searchMatrix(matrix2, target3) ? "true" : "false") << endl; // Expected: false

    // Test case 4: Single element matrix (target present)
    vector<vector<int>> matrix3 = {{5}};
    int target4 = 5;
    cout << "Test case 4 (Single element - target present): " << (sol.searchMatrix(matrix3, target4) ? "true" : "false") << endl; // Expected: true

    // Test case 5: Single element matrix (target not present)
    int target5 = 3;
    cout << "Test case 5 (Single element - target not present): " << (sol.searchMatrix(matrix3, target5) ? "true" : "false") << endl; // Expected: false

    return 0;
}