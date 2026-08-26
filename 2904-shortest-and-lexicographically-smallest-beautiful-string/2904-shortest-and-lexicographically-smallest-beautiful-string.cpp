class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        vector<int> indices;
        for(int i=0;i<n;i++){
            if(s[i]=='1') indices.push_back(i);
        }
        if (indices.size() < k) return "";
        int len=INT_MAX;
        string ans="";
        
        for (int i=0;i+k-1<indices.size();i++){
            int currLen = indices[i+k-1] - indices[i]+1;
            string curr = s.substr(indices[i],currLen);

            if (currLen<len or (currLen==len && curr<ans)) {
                len = currLen;
                ans = curr;
            }
        }
        return ans;
    }
};