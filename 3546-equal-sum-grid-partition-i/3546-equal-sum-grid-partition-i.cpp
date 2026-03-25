using ll=long long;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<ll> row(m,0),col(n,0);
        ll total=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i]+=grid[i][j];
                col[j]+=grid[i][j];
                total+=grid[i][j];
            }
        }
        if(total%2!=0) return false;
        ll up=0;
        for(int i=0;i<m-1;i++){
            up+=row[i];
            if(up==total-up) return true;
        }
        ll left=0;
        for(int i=0;i<n-1;i++){
            left+=col[i];
            if(left==total-left) return true;
        }
        return false;
    }
};