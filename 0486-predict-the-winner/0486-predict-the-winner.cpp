class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,vector<int>& nums){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int takeleft=nums[i]+min(solve(i+1,j-1,nums),solve(i+2,j,nums));
        int takeright=nums[j]+min(solve(i,j-2,nums),solve(i+1,j-1,nums));
        return dp[i][j]=max(takeleft,takeright);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,vector<int>(n,INT_MIN));
        int sum=0;
        for(int ele: nums) sum+=ele;
        return solve(0,n-1,nums)*2>=sum;
    }
};
// class Solution {
// public:
//     vector<vector<int>> dp;
//     int solve(int l,int r,vector<int>& nums){
//         if(l==r) return nums[l];
//         if(dp[l][r]!=INT_MIN) return dp[l][r];

//         int takeleft=nums[l]-solve(l+1,r,nums);
//         int takeright=nums[r]-solve(l,r-1,nums);
//         return dp[l][r]=max(takeleft,takeright);
//     }
//     bool predictTheWinner(vector<int>& nums) {
//         int n=nums.size();
//         dp.assign(n,vector<int>(n,INT_MIN));
//         return solve(0,n-1,nums)>=0;
//     }
// };