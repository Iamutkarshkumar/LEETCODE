class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int idx;
        for(auto &q : queries){
            int l=q[0],r=q[1],k=q[2],v=q[3];
            idx=l;
            while(idx<=r){
                const int MOD=1e9+7;
                nums[idx]=((long long)nums[idx]*(long long)v)%MOD;
                idx+=k;
            }
        }
        for(int i=1;i<nums.size();i++) nums[i]^=nums[i-1];
        return nums[nums.size()-1];
    }
};