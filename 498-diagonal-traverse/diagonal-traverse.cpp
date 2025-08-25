class Solution {
public:
    vector<int> ans;
    int row, col;

    // start at (i,j) and go up-right: i--, j++
    void trav1(int i, int j, vector<vector<int>>& mat){
        while(i>=0 && i<row && j>=0 && j<col){
            ans.push_back(mat[i][j]);
            i--; j++;
        }
    }

    // start at (i,j) and go down-left: i++, j--
    void trav2(int i, int j, vector<vector<int>>& mat){
        while(i>=0 && i<row && j>=0 && j<col){
            ans.push_back(mat[i][j]);
            i++; j--;
        }
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty()) return {};
        row = mat.size();
        col = mat[0].size();
        for(int k = 0; k <= row + col - 2; k++){
            if(k % 2 == 0){
                int i = min(k, row - 1);
                int j = k - i;
                trav1(i, j, mat); // bottom -> top for even k
            } else {
                int j = min(k, col - 1);
                int i = k - j;
                trav2(i, j, mat); // top -> bottom for odd k
            }
        }
        return ans;
    }
};
