// class Solution {
// public:
//     int v[46];
//     int solve(int n){
//         if(n<0) return 0;
//         if(v[n]!=-1) return v[n];
//         if(n==0) return 1;
//         int one_step=solve(n-1);
//         int two_step=solve(n-2);
//         return v[n]=one_step+two_step;
//     }
//     int climbStairs(int n) {
//         memset(v,-1,sizeof(v));
//         return solve(n);
//     }
// };
class Solution {
public:
    int climbStairs(int n) {
        int a=1,b=2,ans;
        if(n<3) return n;
        for(int i=3;i<=n;i++){
            ans=a+b;
            a=b;
            b=ans;
        }
        return ans;   
    }
};