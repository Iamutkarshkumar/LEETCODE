class Solution {
public:
    vector<int> targetIndices(vector<int>& v, int t) {
        sort(v.begin(),v.end());
        int lb=lower_bound(v.begin(),v.end(),t)-v.begin();
        int ub=upper_bound(v.begin(),v.end(),t)-v.begin();
        vector<int> ans;
        for(int i=lb;i<ub;i++) ans.push_back(i);
        return ans;
    }
};