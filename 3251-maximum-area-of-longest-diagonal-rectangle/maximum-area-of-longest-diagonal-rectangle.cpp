class Solution {
public:
    long long diagonal(int l,int b){
        return 1LL*l*l + 1LL*b*b; // return squared diagonal
    }
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long mxarea = 0;
        long long mxdiag = -1;
        for(auto &ele: dimensions){
            long long diag = diagonal(ele[0],ele[1]);
            long long area = 1LL*ele[0]*ele[1];
            if(diag > mxdiag){
                mxdiag = diag;      // <-- update mxdiag too
                mxarea = area;
            } else if(diag == mxdiag) mxarea = max(mxarea, area);
        }
        return (int)mxarea;
    }
};
