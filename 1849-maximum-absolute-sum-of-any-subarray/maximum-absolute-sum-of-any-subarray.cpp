// class Solution {
// public:
//     int maxAbsoluteSum(vector<int>& nums) {
//         int n=nums.size();
//         int preSum=0,minSum=INT_MAX,maxSum=INT_MIN;

//         for(auto ele: nums){
//             preSum+=ele;
//             minSum=min(minSum,preSum);
//             maxSum=max(maxSum,preSum);
//         } 
//         return maxSum-minSum;
//     }
// };
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minPrefixSum = 0, maxPrefixSum = 0;

        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            minPrefixSum = min(minPrefixSum, prefixSum);
            maxPrefixSum = max(maxPrefixSum, prefixSum);
        }

        return maxPrefixSum - minPrefixSum;
    }
};