class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long last = LLONG_MIN;  // last chosen number
        int ans = 0;

        for(long long num : nums) {
            long long start = num - k;
            long long end = num + k;
            // Choose the smallest number >= last+1 within [start, end]
            long long chosen = max(last + 1, start);
            if(chosen <= end) {
                ans++;
                last = chosen;
            }
        }
        return ans;
    }
};
