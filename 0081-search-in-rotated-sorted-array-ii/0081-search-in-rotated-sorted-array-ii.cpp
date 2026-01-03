class Solution {
public:
    bool BS(vector<int>& nums,int low,int high,int t){
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==t){
                return true;
            }
            else if(nums[mid]>t) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
    int findPivot(vector<int>& nums){
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            while(l<r and nums[l]==nums[l+1]) l++;
            while(l<r and nums[r]==nums[r-1]) r--;
            int m=l+(r-l)/2;
            if(nums[m]>nums[r]) l=m+1;
            else r=m;
        }
        return l;
    }
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot=findPivot(nums);
        if(BS(nums,0,pivot-1,target)) return true;
        return BS(nums,pivot,n-1,target);
    }
};