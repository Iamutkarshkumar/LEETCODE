class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // priority_queue<int> pq;
        int ans=INT_MIN;
        sort(begin(nums),end(nums));
        int n=nums.size();
        for(int i=0;i*2<n;i++) ans=max(ans,(nums[i]+nums[n-1-i]));
        return ans;
    }
};