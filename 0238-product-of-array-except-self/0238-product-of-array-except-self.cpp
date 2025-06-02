class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //METHOD 1
        // int n=nums.size();
        // vector<int> ans(n);
        // int pro=1;
        // int zeroCount=0;
        // for(int i=0; i<n; i++){
        //     if (nums[i]==0){
        //         zeroCount++;
        //     }
        // }
        // for(int i=0; i<n; i++){
        //     if(nums[i]!=0){
        //         pro*=nums[i];
        //     }
            
        // }
        // if(zeroCount>1){
        //     for(int i=0; i<n ;i++){
        //         ans[i]=0;
        //     }
        // }
        // else{
        //     for(int i=0; i<n;i++){
        //         if(zeroCount==0){
        //         ans[i]=pro/nums[i];
        //         }
        //         else{
        //             if(nums[i]!=0){
        //                 ans[i]=0;
        //             }
        //             else{
        //                 ans[i]=pro;
        //             }
        //         }
        //     }
        // }
        // return ans;

        //METHOD 2
        int n=nums.size();
        vector<int> pre(n);
        vector<int> sur(n);
        int prod=1;
        pre[0]=1;
        sur[n-1]=1;
        for(int i=1;i<n;i++){
            prod*=nums[i-1];
            pre[i]=prod;
        }
        prod=1;
        for(int i=n-2;i>=0;i--){
            prod*=nums[i+1];
            sur[i]=prod;
        }
        for(int i=0;i<n;i++){
            nums[i]=(pre[i]*sur[i]);
        }
        return nums;
    }
};