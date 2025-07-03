class Solution {
public:
    int t[101];
    int solve(int i,vector<int>& nums,int n){
        if(i>n) return 0;
        if(t[i]!=-1) return t[i];
        int steal=nums[i]+solve(i+2,nums,n);
        int skip=solve(i+1,nums,n);
        return t[i]=max(skip,steal);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        memset(t,-1,sizeof(t));
        int take_0th_idx=solve(0,nums,n-2);
        memset(t,-1,sizeof(t));
        int take_1st_idx=solve(1,nums,n-1);
        return max(take_0th_idx,take_1st_idx);
    }
};