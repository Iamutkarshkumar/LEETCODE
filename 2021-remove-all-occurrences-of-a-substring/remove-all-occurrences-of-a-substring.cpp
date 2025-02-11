class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans="";
        for(int i=0;i<s.length();i++){
            ans.push_back(s[i]);
            if(ans.length()>=part.length() and ans.substr(ans.length()-part.length())==part){
                ans.erase(ans.length()-part.length());
            }
        }
        return ans;
    }
};