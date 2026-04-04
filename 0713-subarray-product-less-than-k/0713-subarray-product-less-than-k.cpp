class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size(),ans=0;
        int i=0,j=0;
        long long prod=1;
        while(j<n){
            prod*=nums[j];
            while(i<=j and prod>=k){
                prod/=nums[i];
                i++;
            }   
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
};