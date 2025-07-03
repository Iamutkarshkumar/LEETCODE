class Solution {
public:
    char kthCharacter(int k) {
        string ans="a";
        while(ans.length()<k){
            string s="";
            for(auto ele: ans){
                s.push_back((char)(((ele + 1 - 'a') % 26) + 'a'));
            }
            ans+=s;
        }
        return ans[k-1];
    }
};