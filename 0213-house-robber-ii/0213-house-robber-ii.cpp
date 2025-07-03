class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> t(n+1,0);
        t[0]=0;
        for(int i=1;i<=n-1;i++){
            int steal=nums[i-1]+((i-2>=0) ? t[i-2] : 0);
            int skip=t[i-1];
            t[i]=max(steal,skip);
        }
        int result1=t[n-1];
        t.clear();
        t[0]=0;
        t[1]=0;
        for(int i=2;i<=n;i++){
            int steal=nums[i-1]+((i-2>=0) ? t[i-2] : 0);
            int skip=t[i-1];
            t[i]=max(steal,skip);
        }
        int result2=t[n];
        return max(result1,result2);
    }
};
// class Solution {
// public:
//     int t[101];
//     int solve(int i,vector<int>& nums,int n){
//         if(i>n) return 0;
//         if(t[i]!=-1) return t[i];
//         int steal=nums[i]+solve(i+2,nums,n);
//         int skip=solve(i+1,nums,n);
//         return t[i]=max(skip,steal);
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1) return nums[0];
//         if(n==2) return max(nums[0],nums[1]);
//         memset(t,-1,sizeof(t));
//         int take_0th_idx=solve(0,nums,n-2);
//         memset(t,-1,sizeof(t));
//         int take_1st_idx=solve(1,nums,n-1);
//         return max(take_0th_idx,take_1st_idx);
//     }
// };