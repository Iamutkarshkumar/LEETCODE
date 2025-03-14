class Solution {
public:
    int LB(vector<int>& nums, int target){
        int n=nums.size();
        int l=0,r=n-1,ans=n;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]>=target){
                ans=min(ans,m);
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
    int UB(vector<int>& nums, int target){
        int n=nums.size();
        int l=0,r=n-1,ans=n;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]>target){
                ans=min(ans,m);
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l = LB(nums, target);
        if(l == nums.size() || nums[l] != target)
            return {-1, -1};  // target not found
        int r = UB(nums, target);
        return {l, r - 1};
    }
};