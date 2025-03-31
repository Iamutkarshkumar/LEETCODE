class Solution {
public:
    int minPairSum(vector<int>& nums) {
        priority_queue<int> pq;
        sort(begin(nums),end(nums));
        int n=nums.size();
        for(int i=0;i*2<n;i++) pq.push(nums[i]+nums[n-1-i]);
        return pq.top();
    }
};