class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    row[j]++;
                    col[i]++;
                }
            }    
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    count+=row[j]>1 or col[i]>1;
                }
            }
        }
        return count;
    }
};