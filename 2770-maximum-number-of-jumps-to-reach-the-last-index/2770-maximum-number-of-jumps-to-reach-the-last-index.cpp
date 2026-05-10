class Solution {
public:
    int n;
    int f(int i,vector<int>& nums,int target,vector<int>& dp){
        if(i==n-1) return 0;
        if(dp[i]!=INT_MIN) return dp[i];
        int ans=-1;

        for(int j=i+1;j<n;j++){
            if(abs(nums[j]-nums[i])<=target){
                int take=f(j,nums,target,dp);

                if(take!=-1)
                    ans=max(ans,1+take);
            }
        }

        return dp[i]=ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        // int ans=0;
        // int i=0,n=nums.size();
        // for(int j=1;j<n;j++){
        //     if(nums[j]-nums[i]<= target and nums[j]-nums[i]>=-1*target){
        //         ans++;
        //         i=j;
        //     }
        // }
        // return (i==n-1 ? ans : -1);

        //above greedy solution is wrong because taking 
        //the first possible jump does not always give the maximum number of jumps

        n=nums.size();
        vector<int> dp(1500);
        for(int i=0;i<1500;i++) dp[i]=INT_MIN;
        return f(0,nums,target,dp);

    }
};