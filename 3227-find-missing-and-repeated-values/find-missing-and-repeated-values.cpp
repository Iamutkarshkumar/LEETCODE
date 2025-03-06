class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<int> ans(n*n,0);
        for(int i=0;i<n;i++){
            for(auto ele: grid[i]) ans[ele-1]++;
        }
        int a,b;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==2) a=i+1;
            if(ans[i]==0) b=i+1;
        }
        return {a,b};
    }
};