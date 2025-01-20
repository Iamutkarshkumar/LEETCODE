class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Assuming it's a square matrix
        int expectedSum = n * (n + 1) / 2;

        // Check row sums
        for (int i = 0; i < n; ++i) {
            int rowSum = 0;
            unordered_set<int> rowSet;
            for (int j = 0; j < n; ++j) {
                rowSum += matrix[i][j];
                rowSet.insert(matrix[i][j]);
            }
            if (rowSum != expectedSum || rowSet.size() != n) {
                return false; // Row is invalid
            }
        }

        // Check column sums
        for (int j = 0; j < n; ++j) {
            int colSum = 0;
            unordered_set<int> colSet;
            for (int i = 0; i < n; ++i) {
                colSum += matrix[i][j];
                colSet.insert(matrix[i][j]);
            }
            if (colSum != expectedSum || colSet.size() != n) {
                return false; // Column is invalid
            }
        }

        return true; // All rows and columns are valid
    }
};
