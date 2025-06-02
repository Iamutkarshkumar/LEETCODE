// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
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
