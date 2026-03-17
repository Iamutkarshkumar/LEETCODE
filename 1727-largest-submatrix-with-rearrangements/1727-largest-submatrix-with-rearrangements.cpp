class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ans=INT_MIN;
        int m=matrix.size(),n=matrix[0].size();
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1) matrix[i][j]+=matrix[i-1][j];
            }
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        for(vector<int> ele: matrix){
            sort(ele.begin(),ele.end(),greater<int>());
            for(int i=0;i<n;i++) ans=max(ans,ele[i]*(i+1));
        }
        return ans;
    }
};