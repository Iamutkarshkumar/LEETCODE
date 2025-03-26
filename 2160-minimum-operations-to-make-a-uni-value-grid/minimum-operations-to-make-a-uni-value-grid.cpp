class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        int ans=INT_MAX;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[0][0]%x != grid[i][j]%x) return -1;
                v.push_back(grid[i][j]);
            }
        }
        sort(begin(v),end(v));
        int l=v.size();

        vector<int> pre(l,0);
        vector<int> suf(l,0);
        for (int i=1;i<l;i++) {
            pre[i] = pre[i-1] + v[i-1];
        }
        for (int i=l-2;i>=0;i--) {
            suf[i] = suf[i+1] + v[i+1];
        }
        for (int i=0;i<l;i++) {
            int leftOperations = (v[i] * i - pre[i]) / x;
            int rightOperations = (suf[i] - v[i]*(l-i-1)) / x;
            ans = min(ans, leftOperations + rightOperations);
        }
        return ans;
    }
};