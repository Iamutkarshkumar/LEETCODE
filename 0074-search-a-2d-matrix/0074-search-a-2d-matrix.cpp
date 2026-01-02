//O(log(m*n))

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x=matrix.size();
        int y=matrix[0].size();
        int l=0,r=x*y-1;
        while(l<=r){
            int m=l+(r-l)/2;
            int row=m/y;
            int col=m%y;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) r=m-1;
            else l=m+1;
        }
        
        return false;
    }
};

/////O(m*log(n))
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int rows=matrix.size();
//         int cols=matrix[0].size();

//         for(int i=0;i<rows;i++){
//             if(matrix[i][cols-1]<target) continue;

//             int l=0,r=cols-1;
//             while(l<=r){
//                 int m=l+(r-l)/2;
//                 if(matrix[i][m]==target) return true;
//                 else if(matrix[i][m]>target) r=m-1;
//                 else l=m+1;
//             }
//         }
//         return false;
//     }
// };