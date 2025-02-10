class Solution {
public:
    string clearDigits(string s) {
        stack<char> help;
        string ans="";
        for(auto ele: s){
            if(ele-'0'>=0 and ele-'0'<=9) help.pop();
            else help.push(ele);
        }
        while(not help.empty()){
            char x=help.top();help.pop();
            ans.push_back(x);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};