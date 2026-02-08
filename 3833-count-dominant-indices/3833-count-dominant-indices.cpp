class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto ele: nums) sum+=ele;

        int ans=0;
        for(int i=0;i<n-1;i++){
            sum-=nums[i];
            int x=n-1-i;
            if((long long)nums[i]*x>sum) ans++;
        }
        return ans;
    }
};