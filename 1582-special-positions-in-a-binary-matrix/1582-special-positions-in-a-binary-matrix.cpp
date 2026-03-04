class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int r=mat.size(),c=mat[0].size();
        vector<int> row(r,0),col(c,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==1 and row[i]==1 and col[j]==1) ans++;
            }
        }
        return ans;
    }
};