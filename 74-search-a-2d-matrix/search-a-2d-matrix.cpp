class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto ele: matrix){
            if(binary_search(begin(ele),end(ele),target)) return true;
        }
        return false;
    }
};