class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans;
        for(auto &ele: matrix){
            int count=0;
            for(auto x: ele) count+=(x==1);
            ans.push_back(count);
        }
        return ans;
    }
};