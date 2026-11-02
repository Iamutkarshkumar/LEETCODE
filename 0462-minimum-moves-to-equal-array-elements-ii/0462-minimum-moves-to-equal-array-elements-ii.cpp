class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int x=nums[(n-1)/2];
        int ans=0;
        for(auto &ele: nums) ans+=(abs(ele-x));
        return ans;
    }
};