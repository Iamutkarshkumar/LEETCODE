class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(auto ele: guards) ans[ele[0]][ele[1]]=2;
        for(auto ele: walls) ans[ele[0]][ele[1]]=3;

        for(auto ele: guards){
            int r=ele[0];
            int c=ele[1];
            //up
            for(int i=r-1;i>=0;i--){
                if(ans[i][c]==2 or ans[i][c]==3) break;
                ans[i][c]=1;
            }
            //down
            for(int i=r+1;i<m;i++){
                if(ans[i][c]==2 or ans[i][c]==3) break;
                ans[i][c]=1;
            }
            //left
            for(int i=c-1;i>=0;i--){
                if(ans[r][i]==2 or ans[r][i]==3) break;
                ans[r][i]=1;
            }
            //right
            for(int i=c+1;i<n;i++){
                if(ans[r][i]==2 or ans[r][i]==3) break;
                ans[r][i]=1;
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j]==0) count++;
            }
        }
        return count;
    }
};