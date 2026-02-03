class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int a=1,b=2;
        int ans;
        for(int i=3;i<=n;i++){
            ans=a+b;
            a=b;
            b=ans;
        }
        return ans;
    }
};
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n<=2) return n;
//         vector<int> dp(n+1,0);
//         dp[1]=1;
//         dp[2]=2;
//         for(int i=3;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
//         return dp[n];
//     }
// };


// class Solution {
// public:
//     int solve(int n,vector<int>& dp){
//         if(n<0) return 0;
//         if(n==0) return 1;
//         if(dp[n]!=-1) return dp[n];
//         int oneStep=solve(n-1,dp);
//         int twoStep=solve(n-2,dp);
//         return dp[n]=oneStep+twoStep;
//     }
//     int climbStairs(int n) {
//         vector<int> dp(n+1,-1);
//         return solve(n,dp);
//     }
// };