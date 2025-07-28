class Solution {
public:
    using ll=long long;
    long long maximumMedianSum(vector<int>& nums) {
        sort(begin(nums),end(nums));

        ll ans=0;
        int n=nums.size();
        int i=0,j=n-1;
        while(i<j){
            ans+=nums[j-1];
            i++;
            j-=2;
        }
        return ans;
    }
};