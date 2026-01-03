class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target) return true;
            if(nums[l]==nums[m] and nums[m]==nums[r]){
                l++;r--;
            }
            //left half sorted 
            else if(nums[l]<=nums[m]){
                if(nums[l]<=target and nums[m]>target) r=m-1;
                else l=m+1;
            }
            //right half sorted
            else{
                if(nums[m]<target and nums[r]>=target) l=m+1;
                else r=m-1;
            }
        }
        return false;
    }
};