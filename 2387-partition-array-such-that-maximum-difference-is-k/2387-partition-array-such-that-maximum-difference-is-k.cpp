class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int ans=1;
        int curr=nums[0];
        for(int i=1;i<nums.size();i++){
            if((nums[i]-curr)<=k) continue;
            else{
                ans++;
                curr=nums[i];
            }
        }
        return ans;
    }
};