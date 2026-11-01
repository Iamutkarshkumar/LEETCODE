class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        int mn=*min_element(begin(nums),end(nums));
        for(auto ele: nums) ans+=(ele-mn); 
        return ans;
    }
};