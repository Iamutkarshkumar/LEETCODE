class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> t(n+1,0);
        t[0]=0;
        t[1]=nums[0];
        for(int i=2;i<=n;i++){
            int steal=nums[i-1]+t[i-2];
            int skip=t[i-1];
            t[i]=max(steal,skip);
        }
        return t[n];
    }
};
// class Solution {
// public:
//     int t[101];
//     int solve(int i,vector<int>& nums){
//         if(i>=nums.size()) return 0;
//         if(t[i]!=-1) return t[i];
//         int steal=nums[i]+solve(i+2,nums);
//         int skip=solve(i+1,nums);
//         return t[i]=max(steal,skip);
//     }
//     int rob(vector<int>& nums) {
//         memset(t,-1,sizeof(t));
//         return solve(0,nums);
//     }
// };