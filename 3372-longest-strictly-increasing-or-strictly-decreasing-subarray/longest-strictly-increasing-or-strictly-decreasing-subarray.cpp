class Solution {
public:
    bool isStrictlyIncreasing(vector<int>& nums, int i, int j) {
        for (int k = i; k < j; k++) {
            if (nums[k] >= nums[k + 1]) {
                return false;
            }
        }
        return true;
    }

    bool isStrictlyDecreasing(vector<int>& nums, int i, int j) {
        for (int k = i; k < j; k++) {
            if (nums[k] <= nums[k + 1]) {
                return false;
            }
        }
        return true;
    }

    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isStrictlyIncreasing(nums, i, j) || isStrictlyDecreasing(nums, i, j)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};