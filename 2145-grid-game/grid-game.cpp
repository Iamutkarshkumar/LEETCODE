class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> topPrefix(n, 0), bottomPrefix(n, 0);

        // Compute prefix sums for the top and bottom rows
        topPrefix[0] = grid[0][0];
        bottomPrefix[0] = grid[1][0];
        for (int i = 1; i < n; i++) {
            topPrefix[i] = topPrefix[i - 1] + grid[0][i];
            bottomPrefix[i] = bottomPrefix[i - 1] + grid[1][i];
        }

        // Compute the minimum maximum score for the second robot
        long long result = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            // Points collected above (top row after column `i`)
            long long pointsAbove = (i == n - 1) ? 0 : topPrefix[n - 1] - topPrefix[i];

            // Points collected below (bottom row before column `i`)
            long long pointsBelow = (i == 0) ? 0 : bottomPrefix[i - 1];

            // Second robot collects the maximum of the two remaining paths
            long long secondRobotPoints = max(pointsAbove, pointsBelow);
            result = min(result, secondRobotPoints);
        }

        return result;
    }
};
