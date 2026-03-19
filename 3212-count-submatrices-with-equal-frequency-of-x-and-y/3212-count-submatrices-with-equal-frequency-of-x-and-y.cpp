class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=0;
        vector<vector<int>> v(m,vector<int>(n,0));
        vector<vector<int>> cntX(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='X') v[i][j]=1;
                else if(grid[i][j]=='Y') v[i][j]=-1;
                if(grid[i][j]=='X') cntX[i][j]=1;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                v[i][j]+=v[i][j-1];
                cntX[i][j]+=cntX[i][j-1];
            }
        }
        for(int j=0;j<n;j++){
            for(int i=1;i<m;i++){
                v[i][j]+=v[i-1][j];
                cntX[i][j]+=cntX[i-1][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==0 and cntX[i][j]>0) ans++;
            }
        }
        return ans;
    }
};