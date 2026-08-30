class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mx=0,mn=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[mx]) mx=i;
            if(nums[i]<nums[mn]) mn=i;
        }
        if (mn>mx) swap(mn,mx);
        int left = mx + 1;// remove from left
        int right = n - mn;//remove from right
        int both = (mn + 1) + (n - mx);// Remove mn from left and mx from right
        return min({left, right, both});
    }
};