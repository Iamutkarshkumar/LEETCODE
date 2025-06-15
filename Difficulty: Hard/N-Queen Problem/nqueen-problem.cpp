class Solution {
  public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        vector<int> cur(n);
        vector<bool> col(n), d1(2*n), d2(2*n);
        function<void(int)> dfs = [&](int c){
            if(c==n){ res.push_back(cur); return; }
            for(int r=0;r<n;r++){
                if(col[r]||d1[c+r]||d2[n+c-r]) continue;
                col[r]=d1[c+r]=d2[n+c-r]=true;
                cur[c]=r+1;
                dfs(c+1);
                col[r]=d1[c+r]=d2[n+c-r]=false;
            }
        };
        dfs(0);
        return res;
    }
};
