class Solution {
public:
    int n;
    vector<int> dp;

    int solve(int i, vector<int>& v) {
        if (i >= n) return 0;
        if (dp[i] != INT_MIN) return dp[i];

        int sum = 0;
        int ans = INT_MIN;

        for (int k = 0; k < 3 && i + k < n; k++) {
            sum += v[i + k];
            ans = max(ans, sum - solve(i + k + 1, v));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.assign(n + 1, INT_MIN);
        dp[n] = 0;

        int diff = solve(0, stoneValue);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};