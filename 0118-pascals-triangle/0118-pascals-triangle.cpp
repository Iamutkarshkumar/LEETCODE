class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector < vector<int> > v;
        int n=numRows;
        for(int i=1 ; i<=n ; i++){
            vector<int> a(i);
            v.push_back(a);
            
        }
        for(int i=0  ; i<n ; i++){
            for(int j=0 ; j<=i ; j++){
                if(j==0 || j==i) v[i][j]=1;
                else v[i][j]=v[i-1][j]+v[i-1][j-1];
            }
        }
        return v;
        
        
    }
};