class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
            int x=mp[nums[i]].size();
            if(x>=3){
                auto &v = mp[nums[i]];
                int k=v[x-1];
                ans=min(ans,2*(k-v[x-3]));
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};