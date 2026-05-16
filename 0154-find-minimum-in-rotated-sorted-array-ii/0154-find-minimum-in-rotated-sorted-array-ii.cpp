class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r and nums[l]==nums[l+1]) l++;
        while(l<r and nums[r-1]==nums[r]) r--;
        while(l<r){
            int m=l+(r-l)/2;
            if(nums[m]>nums[r]) l=m+1;
            else r=m;
        }
        return nums[l];
    }
};