class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int r=*max_element(nums.begin(),nums.end());
        vector<bool> vis(r+1,false);
        vector<int> ans;
        for(int i=0;i<n;i++) vis[nums[i]]=true;
        int idx=0;
        while(!vis[idx]) idx++;
        idx++;
        while(idx<=r){
            if(!vis[idx]) ans.push_back(idx);
            idx++;
        }
        return ans;
    }
};