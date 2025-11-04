class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int l=*min_element(nums.begin(),nums.end());
        int r=*max_element(nums.begin(),nums.end());
        unordered_set<int> s(begin(nums),end(nums));
        vector<int> ans;
        for(int i=l;i<=r;i++){
            if(s.count(i)==0) ans.push_back(i);
        }
        return ans;
    }
};