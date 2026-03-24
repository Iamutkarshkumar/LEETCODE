using ll=long long;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        ll MOD = 12345;
        ll suffix=1;
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                ans[i][j]=suffix;
                suffix = (suffix*grid[i][j])%MOD;
            }
        }
        ll prefix=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=(ans[i][j]*prefix)%MOD;
                prefix = (prefix*grid[i][j])%MOD;
            }
        }
        return ans;
    }
};