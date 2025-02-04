class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxsum=0;
        int sum=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]) sum+=nums[i];
            else{
                maxsum=max(maxsum,sum);
                sum=nums[i];
            }
        }
        return max(maxsum,sum);
    }
};
// class Solution {
// public:
//     int maxAscendingSum(vector<int>& nums) {
//         int maxSum=INT_MIN;
//         int n=nums.size();
//         vector<int> help;
//         if(n==1) return nums[0];
//         int i=0;
//         int sum=0;
//         for(int i=0;i<n;i++){
//             int sum=nums[i];
//             int j=i+1;
//             while(j<n and nums[j]>nums[j-1]){
//                 sum+=nums[j];
//                 j++;
//             }
//             maxSum=max(sum,maxSum);
//         }
//         return maxSum;

//     }
// };