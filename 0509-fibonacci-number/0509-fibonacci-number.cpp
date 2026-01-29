// method 1: Top-down DP (Recursion + Memoization)
// class Solution {
// public:
//     int solve(int n,vector<int>& dp){
//         if(n<=1) return n; //base case
//         if(dp[n]!=-1) return dp[n];
//         return dp[n]=solve(n-1,dp)+solve(n-2,dp);
//     }
//     int fib(int n) {
//         vector<int> dp(n+1,-1);
//         return solve(n,dp);
//     }
// };

//method 2: Bottom-up
// class Solution {
// public:
//     int fib(int n) {
//         if(n<=1) return n;
//         vector<int> dp(n+1,-1);
//         dp[0]=0;
//         dp[1]=1;
//         for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
//         return dp[n];
//     }
// };

//method 3: constant SC
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int a=0,b=1;
        int ans;
        for(int i=2;i<=n;i++){
            ans=a+b;
            a=b;
            b=ans;
        }
        return ans;
    }
};