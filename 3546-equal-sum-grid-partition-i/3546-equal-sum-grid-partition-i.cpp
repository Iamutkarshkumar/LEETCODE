using ll=long long;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<ll> row,col;
        for(int i=0;i<m;i++){
            ll sum=0;
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
            }
            row.push_back(sum);
        }
        for(int j=0;j<n;j++){
            ll sum=0;
            for(int i=0;i<m;i++){
                sum+=grid[i][j];
            }
            col.push_back(sum);
        }
        for(int i=1;i<row.size();i++) row[i]+=row[i-1];
        for(int i=1;i<col.size();i++) col[i]+=col[i-1];
        for(int i=0;i<row.size();i++){
            if(row[i]==row[row.size()-1]-row[i]) return true;
        }
        for(int i=0;i<col.size();i++){
            if(col[i]==col[col.size()-1]-col[i]) return true;
        }
        return false;
    }
};