class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        while(i>=0 and nums[i]>=nums[i+1]) i--;
        if(i>=0){
            int j=n-1;
            while(j>=0){
                if(nums[j]>nums[i]){
                    swap(nums[j],nums[i]);
                    break;
                }
                j--;
            }
        }
        reverse(begin(nums)+i+1,end(nums));
    }
};