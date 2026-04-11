class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int idx=0;idx<n;idx++){
            mp[nums[idx]].push_back(idx);
            int x=mp[nums[idx]].size();
            if(x>=3){
                int k=mp[nums[idx]][x-1];
                int i=mp[nums[idx]][x-3];
                ans=min(ans,2*(k-i));
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};