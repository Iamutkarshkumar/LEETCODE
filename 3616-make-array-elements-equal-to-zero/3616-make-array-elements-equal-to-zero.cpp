class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 && nums[0] == 0) return 2;
        int total = 0;
        for(int x: nums) total += x;
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) prefix[i] = prefix[i-1] + nums[i];
        int ans = 0;
        for(int i = 0; i < n; i++) if(nums[i] == 0) {
            int l = (i == 0 ? 0 : prefix[i-1]);
            int r = total - prefix[i];
            if(l == r) ans += 2;
            else if(std::abs(l - r) == 1) ans += 1;
        }
        return ans;
    }
};
