class Solution {
public:
    int v[46];
    int solve(int n){
        if(n<0) return 0;
        if(v[n]!=-1) return v[n];
        if(n==0) return 1;
        int one_step=solve(n-1);
        int two_step=solve(n-2);
        return v[n]=one_step+two_step;
    }
    int climbStairs(int n) {
        memset(v,-1,sizeof(v));
        return solve(n);
    }
};