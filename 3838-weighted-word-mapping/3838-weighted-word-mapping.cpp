class Solution {
public:
    inline int help(string s,vector<int>& weights){
        int sum=0;
        for(int i=0;i<s.length();i++){
            sum+=weights[s[i]-'a'];
        }
        return sum%26;
    }
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n=words.size();
        string ans;
        for(auto ele: words){
            int sum=help(ele,weights);
            char x=25-sum+'a';
            ans.push_back(x);
        }
        return ans;
    }
};