class Solution {
  public:
	void floydWarshall(vector<vector<int>>& grid){
        int n = grid.size();
        for(int via = 0; via < n; via++) {
            for(int i = 0; i<n; i++) {
                if (grid[i][via] == 1e8) continue;
                for(int j = 0; j<n; j++) {
                    if (grid[via][j] == 1e8) continue;
                    grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                }
            }
        }
	}
};