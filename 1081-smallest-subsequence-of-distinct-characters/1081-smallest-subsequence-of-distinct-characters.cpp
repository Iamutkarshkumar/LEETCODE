class Solution {
public:
    string smallestSubsequence(string s) {
        string ans;
        vector<int> vis(26),num(26);
        for(auto ele: s) num[ele-'a']++;

        for(auto ele: s){
            if(!vis[ele-'a']){
                while(!ans.empty() and ans.back()>ele){
                    if(num[ans.back()-'a']>0){
                        vis[ans.back()-'a']=0;
                        ans.pop_back();
                    }
                    else break;
                }
                vis[ele-'a']=1;
                ans.push_back(ele);
            }
            num[ele-'a']-=1;
        }
        return ans;
    }
};