class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return false;
        int i=1;
        // strictly increasing
        while(i<n and nums[i]>nums[i-1]) i++;
        if(i==1 or i==n) return false;
        // strictly decreasing
        while(i<n and nums[i]<nums[i-1]) i++;
        if(i==n) return false;
        // strictly increasing
        while(i<n and nums[i]>nums[i-1]) i++;
        return i==n;
    }
};