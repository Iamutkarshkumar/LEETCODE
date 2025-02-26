class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int preSum=0,minSum=0,maxSum=0;

        for(auto ele: nums){
            preSum+=ele;
            minSum=min(minSum,preSum);
            maxSum=max(maxSum,preSum);
        } 
        return maxSum-minSum;
    }
};