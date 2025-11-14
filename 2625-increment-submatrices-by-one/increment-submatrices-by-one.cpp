class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n,vector<int>(n,0));

        for(auto ele: queries){
            for(int i=ele[0];i<=ele[2];i++){
                for(int j=ele[1];j<=ele[3];j++){
                    ans[i][j]++;
                }
            }
        }
        return ans;
    }
};