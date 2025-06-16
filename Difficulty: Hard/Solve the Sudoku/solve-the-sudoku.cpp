class Solution {
    bool row[9][10]={}, col[9][10]={}, box[9][10]={};
    bool dfs(vector<vector<int>>& m,int i,int j){
        if(i==9) return true;
        int ni=i+(j+1)/9, nj=(j+1)%9;
        if(m[i][j]) return dfs(m,ni,nj);
        int b=(i/3)*3+j/3;
        for(int v=1;v<=9;v++) if(!row[i][v]&&!col[j][v]&&!box[b][v]){
            m[i][j]=v; row[i][v]=col[j][v]=box[b][v]=true;
            if(dfs(m,ni,nj)) return true;
            m[i][j]=0; row[i][v]=col[j][v]=box[b][v]=false;
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<int>>& m) {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++) if(m[i][j]){
                int v=m[i][j], b=(i/3)*3+j/3;
                row[i][v]=col[j][v]=box[b][v]=true;
            }
        dfs(m,0,0);
    }
};
