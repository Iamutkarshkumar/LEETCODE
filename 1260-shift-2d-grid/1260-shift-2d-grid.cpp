class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r=grid.size(),c=grid[0].size();
        vector<int> v;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                v.push_back(grid[i][j]);
            }
        }
        int n=v.size();
        k%=n;
        int rot=(n-k)%n;  
        reverse(begin(v),begin(v)+rot);
        reverse(begin(v)+rot,end(v));
        reverse(begin(v),end(v));
        int idx=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                grid[i][j]=v[idx++];
            }
        }
        return grid;
    }
};