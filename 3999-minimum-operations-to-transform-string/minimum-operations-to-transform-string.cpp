class Solution {
public:
    int minOperations(string s) {
        unordered_set<char> c;
        for(auto ele: s){
            if(ele!='a') c.insert(ele);
        }
        if(c.size()==0) return 0;
        vector<char> help(c.begin(),c.end());
        sort(begin(help),end(help));
        int len=help.size();
        int ans=0;
        for(int i=1;i<len;i++){
            ans+=((help[i]-'a')-(help[i-1]-'a'));
        }
        ans+=26-(help[len-1]-'a');
        return ans;
    }
};