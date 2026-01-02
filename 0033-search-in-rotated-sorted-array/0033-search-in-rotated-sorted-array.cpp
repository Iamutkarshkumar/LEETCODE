class Solution {
public:
    int BS(vector<int>& nums,int low,int high,int t){
        int idx=-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==t){
                idx=mid;
                break;
            }
            else if(nums[mid]>t) high=mid-1;
            else low=mid+1;
        }
        return idx;
    }
    int findPivot(vector<int>& nums){
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int m=l+(r-l)/2;
            if(nums[m]>nums[r]) l=m+1;
            else r=m;
        }
        return l;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot=findPivot(nums);

        int idx=BS(nums,0,pivot-1,target);
        if(idx!=-1) return idx;
        idx=BS(nums,pivot,n-1,target);
        return idx;
    }
};