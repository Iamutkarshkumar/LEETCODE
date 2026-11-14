class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX;
        for(int sz=l;sz<=r;sz++){
            int i=0,j=0;
            int sum=0;
            while(j<nums.size()){
                sum+=nums[j];

                if(j-i+1==sz){
                    if(sum>0) ans=min(ans,sum);
                    sum-=nums[i];
                    i++;
                }
                j++;
            }
        }
        return ans==INT_MAX? -1 : ans;
    }
};