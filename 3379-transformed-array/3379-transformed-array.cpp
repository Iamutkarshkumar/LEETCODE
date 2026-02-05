class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        nums.insert(end(nums),begin(nums),end(nums));
        nums.insert(end(nums),begin(nums),end(nums));
        vector<int> ans;
        for(int i=n;i<2*n;i++){
            int moves=nums[i]%n;
            ans.push_back(nums[i+moves]);
        }
        return ans;
    }
};