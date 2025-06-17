class Solution {
public:
    bool isWordExist(vector<vector<char>>& mat, string& w) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        function<bool(int,int,int)> dfs = [&](int i, int j, int k) {
            if(mat[i][j] != w[k] || vis[i][j]) return false;
            if(k == w.size() - 1) return true;
            vis[i][j] = true;
            int di[4] = {1,-1,0,0}, dj[4] = {0,0,1,-1};
            for(int d = 0; d < 4; ++d) {
                int ni = i + di[d], nj = j + dj[d];
                if(ni >= 0 && nj >= 0 && ni < n && nj < m && dfs(ni, nj, k+1))
                    return true;
            }
            vis[i][j] = false;
            return false;
        };
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(dfs(i, j, 0)) return true;
        return false;
    }
};