class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        // Count "breaks" in the sorted order
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            // If there is more than one break, return false
            if (count > 1) return false;
        }

        return true;
    }
};