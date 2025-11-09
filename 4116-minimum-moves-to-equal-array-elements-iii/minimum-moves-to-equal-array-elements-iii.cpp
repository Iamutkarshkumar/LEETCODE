class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();int ans=0;
        for(int i=0;i<n;i++){
            ans+=(nums[n-1]-nums[i]);
        }
        return ans;
    }
};