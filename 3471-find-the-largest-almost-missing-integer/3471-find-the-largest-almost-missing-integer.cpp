class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(auto ele: nums) mp[ele]++;
        // Case 1: k==n
        if(n==k){
            int ans=-1;;
            for(auto ele: nums) ans=max(ans,ele);
            return ans;
        }
        // Case 2: k == 1
        // Subarrays are size 1. Any element with a total frequency of 1 is valid.
        if (k == 1) {
            int ans = -1;
            for (auto& [val, count] : mp) {
                if (count == 1) {
                    ans = max(ans, val);
                }
            }
            return ans;
        }

        //Case 3: k<n
        int ans=-1;
        if(mp[nums[0]]==1) ans=max(ans,nums[0]);
        if(mp[nums[n-1]]==1) ans=max(ans,nums[n-1]);
        return ans;
    }
};