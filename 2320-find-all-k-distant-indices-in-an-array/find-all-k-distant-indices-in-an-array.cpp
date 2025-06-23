class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> help;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            if(abs(i-j)<=k and nums[j]==key) help.insert(i);
        }
        for(auto ele: help) ans.push_back(ele);
        return ans;
    }
};