class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        for(auto ele: nums) ans|=ele;
        ans=ans<<(nums.size()-1);
        return ans;
    }
};