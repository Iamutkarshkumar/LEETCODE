class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ans=INT_MAX;
        for(auto ele: tasks) ans=min(ans,ele[0]+ele[1]);
        return ans;
    }
};