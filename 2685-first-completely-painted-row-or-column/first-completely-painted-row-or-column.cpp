class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>> mp;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp.insert({mat[i][j],{i,j}});
            }
        }
        vector<int> rowsFreq(m);
        vector<int> colFreq(n);
        for(int k=0;k<arr.size();k++){
            auto x =mp[arr[k]].first;
            auto y =mp[arr[k]].second;
            rowsFreq[x]++;
            if(rowsFreq[x]==n) return k;
            colFreq[y]++;
            if(colFreq[y]==m) return k;
        }
        return m*n;
    }
};