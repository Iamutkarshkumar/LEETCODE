class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string s1=".";
        for(int i=0;i<n-1;i++) s1+='#';
        for(int i=0;i<m-1;i++) ans.push_back(s1);
        string s2;
        for(int i=0;i<n;i++) s2.push_back('.');
        ans.push_back(s2);
        return ans;
    }
};