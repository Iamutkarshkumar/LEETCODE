class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minrow=INT_MAX,mincol=INT_MAX,maxrow=INT_MIN,maxcol=INT_MIN;

        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    minrow=min(minrow,i);
                    mincol=min(mincol,j);
                    maxrow=max(maxrow,i);
                    maxcol=max(maxcol,j);
                }
            }
        }
        int d=maxrow-minrow+1;
        int l=maxcol-mincol+1;
        cout<<d<<" "<<l;
        return d*l;
    }
};