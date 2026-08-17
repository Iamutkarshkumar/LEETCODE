class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int l, int r, vector<int>& pref) {
        // Only one stone -> game ends
        if (l == r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        // Split between j and j+1
        for (int j = l; j < r; j++) {
            int leftSum = pref[j + 1] - pref[l];
            int rightSum = pref[r + 1] - pref[j + 1];

            if (leftSum < rightSum) {
                // Bob throws right part
                // Alice keeps left part
                ans = max(ans, leftSum + solve(l, j, pref));
            }
            else if (rightSum < leftSum) {
                // Bob throws left part
                // Alice keeps right part
                ans = max(ans, rightSum + solve(j + 1, r, pref));
            }
            else {
                // Equal -> Alice chooses whichever is better
                ans = max({
                    ans,
                    leftSum + solve(l, j, pref),
                    rightSum + solve(j + 1, r, pref)
                });
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();

        // prefix sum
        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }

        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1, pref);
    }
};